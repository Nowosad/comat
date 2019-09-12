#include "rcpp_get_coma.h"
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::interfaces(r, cpp)]]

// [[Rcpp::export]]
DataFrame get_motifels(const List y,
                  const arma::imat directions,
                  int size,
                  int shift,
                  std::string what = "coma") {

  IntegerMatrix x = y(0);

  int num_r = x.nrow();
  int num_c = x.ncol();
  int num_l = y.length();

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

  IntegerVector all_m_row(nr_of_motifels);
  IntegerVector all_m_col(nr_of_motifels);

  for (int i = 0; i < num_r; i = i + shift){
    for (int j = 0; j < num_c; j = j + shift){
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

      for (int l = 0; l < num_l; l++){
        if (what == "coma"){
          IntegerMatrix motifel_x = x(Range(i, i_max), Range(j, j_max));
          result[nr_of_motifels2] = rcpp_get_coma(motifel_x, directions);
        }
      }

      // IntegerMatrix motifel_x = x(Range(i, i_max), Range(j, j_max));
      // NumericMatrix motifel_w = w(Range(i, i_max), Range(j, j_max));
      // double na_perc = na_prop(motifel_x);
      // if (na_perc <= na_threshold){
      //
      // }

      nr_of_motifels2 ++;
      m_col++;
    }
    m_col = 1;
    m_row++;
  }
  DataFrame df = DataFrame::create(Named("V1") = all_m_row,
                                   Named("V2") = all_m_col,
                                   Named("V3") = result);
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
get_motifels(a, directions = directions, size = 100, shift = 100)
*/
