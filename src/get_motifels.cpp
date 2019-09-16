#include "rcpp_get_coma.h"
#include "rcpp_get_wecoma.h"
#include "rcpp_get_cocoma.h"
#include "rcpp_get_incoma.h"
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::interfaces(r, cpp)]]

// [[Rcpp::export]]
List get_motifels(const List input,
                  const arma::imat directions,
                  int size,
                  int shift,
                  std::string what = "coma",
                  const std::string fun = "mean",
                  const std::string na_action = "replace") {

  IntegerMatrix x = input(0);
  int num_r = x.nrow();
  int num_c = x.ncol();
  int num_l = input.length();

  NumericMatrix w(num_r, num_c);
  IntegerMatrix y(num_r, num_c);
  std::vector<int> classes_x;
  std::vector<int> classes_y;
  List classes(num_l);

  if (what == "coma"){
    classes_x = get_unique_values(x);
  } else if (what == "wecoma"){
    w = wrap(input(1));
    classes_x = get_unique_values(x);
  } else if (what == "cocoma"){
    y = wrap(input(1));
    classes_x = get_unique_values(x);
    classes_y = get_unique_values(y);
  } else if (what == "incoma"){
    for (int i = 0; i < num_l; i++){
      classes(i) = get_unique_values(input[i]);
    }
  }

  int nr_of_motifels = 0;
  for (int i = 0; i < num_r; i = i + shift) {
    for (int j = 0; j < num_c; j = j + shift) {
      nr_of_motifels ++;
    }
  }

  List result(nr_of_motifels);

  int nr_of_motifels2 = 0;
  int m_row = 1;
  int m_col = 1;

  IntegerVector all_nr_of_motifels(nr_of_motifels);
  IntegerVector all_m_row(nr_of_motifels);
  IntegerVector all_m_col(nr_of_motifels);

  for (int i = 0; i < num_r; i = i + shift){
    for (int j = 0; j < num_c; j = j + shift){
      all_nr_of_motifels(nr_of_motifels2) = nr_of_motifels2 + 1;
      all_m_row(nr_of_motifels2) = m_row;
      all_m_col(nr_of_motifels2) = m_col;

      int i_max = i + (size - 1);
      if (i_max >= num_r){
        i_max = num_r - 1;
      }
      int j_max = j + (size - 1);
      if (j_max >= num_c){
        j_max = num_c - 1;
      }

      if (what == "coma"){
        IntegerMatrix motifel_x = x(Range(i, i_max), Range(j, j_max));
        result[nr_of_motifels2] = rcpp_get_coma_internal(motifel_x, directions, classes_x);
      } else if (what == "wecoma"){
        IntegerMatrix motifel_x = x(Range(i, i_max), Range(j, j_max));
        NumericMatrix motifel_w = w(Range(i, i_max), Range(j, j_max));
        result[nr_of_motifels2] = rcpp_get_wecoma_internal(motifel_x, motifel_w, directions, classes_x, fun, na_action);
      } else if (what == "cocoma"){
        IntegerMatrix motifel_x = x(Range(i, i_max), Range(j, j_max));
        IntegerMatrix motifel_y = y(Range(i, i_max), Range(j, j_max));
        // Rcout << "The value of motifel_x : " << motifel_x << "\n";
        // Rcout << "The value of motifel_y : " << motifel_y << "\n";
        result[nr_of_motifels2] = rcpp_get_cocoma_internal(motifel_x, motifel_y, directions, classes_x, classes_y);
      } else if (what == "incoma"){
        List motifel_input(num_l);
        for (int l = 0; l < num_l; l++){
          IntegerMatrix layer_l = input(l);
          motifel_input(l) = layer_l(Range(i, i_max), Range(j, j_max));
        }
        result[nr_of_motifels2] = rcpp_get_incoma_internal(motifel_input, directions, classes);
      }

      // double na_perc = na_prop(motifel_x);

      nr_of_motifels2 ++;
      m_col++;
    }
    m_col = 1;
    m_row++;
  }
  List df = List::create(Named("id") = all_nr_of_motifels,
                         Named("row") = all_m_row,
                         Named("col") = all_m_col,
                         Named("matrix") = result);
  return df;
}

/*** R
library(raster)
set.seed(10100)
l1 = raster(matrix(sample(1:2, size = 1000000, replace = TRUE), ncol = 1000))
l2 = raster(matrix(sample(c(9, 6, 3), size = 1000000, replace = TRUE), ncol = 1000))
x = stack(l1, l2, l1)
rasters = lapply(raster::as.list(x), raster::as.matrix)
directions = as.matrix(4)
a = list(as.matrix(l1))
res = get_motifels(a, directions = directions, size = 100, shift = 100)
library(tibble)
res_df = as_tibble(res)

get_cove(res_df$V3[[4]])
*/
