#include "rcpp_get_incoma.h"
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::interfaces(r, cpp)]]

// [[Rcpp::export]]
List rcpp_get_incoma(const List x,
                     const arma::imat directions) {
  int v1_len = x.length();
  List classes(v1_len);
  for (int i = 0; i < v1_len; i++){
    classes(i) = get_unique_values(x[i]);
  }

  List result_list = rcpp_get_incoma_list(x, directions, classes);
  // IntegerMatrix result = rcpp_get_incoma_matrix(result_list);
  return result_list;
}

// [[Rcpp::export]]
List rcpp_get_incoma_list(const List x,
                          const arma::imat directions,
                          List classes) {

  int v1_len = x.length();
  List mat_list(v1_len * v1_len);

  int loop = 0;
  for (int i = 0; i < v1_len; i++){
    for (int j = 0; j < v1_len; j++){
      if (i == j){
        mat_list[loop] = rcpp_get_coma_internal(x[i], directions, classes[i]);
      } else {
        mat_list[loop] = rcpp_get_cocoma_internal(x[i], x[j], directions, classes[i], classes[j]);
      }
      loop ++;
    }
  }

  return mat_list;
}

// [[Rcpp::export]]
IntegerMatrix rcpp_get_incoma_matrix(const List x){

  int mat_len = 0;
  int v1_len = std::sqrt(static_cast<double>(x.length()));
  CharacterVector classes_xy;
  NumericVector no_unique(v1_len);
  for (int k = 0; k < v1_len; k++){
    IntegerMatrix x_k = x[k];
    int x_k_ncol = x_k.ncol();
    no_unique(k) = x_k_ncol;
    mat_len = mat_len + x_k_ncol;
    CharacterVector col_names_k = colnames(x_k);
    for (int kka = 0; kka < col_names_k.length(); kka++){
      classes_xy.push_back(col_names_k(kka));
    }
  }

  arma::imat result(0, mat_len);
  int o = 0;
  for (int ii = 0; ii < v1_len; ii++){
    arma::imat x_o = as<arma::imat>(x[o]);
    arma::imat m(x_o.n_rows, 0);
    for (int jj = 0; jj < v1_len; jj++){
      m = arma::join_rows(m, as<arma::imat>(x(o)));
      o = o + 1;
    }
    result = arma::join_cols(result, m);
  }

  // add names
  List u_names = List::create(classes_xy, classes_xy);
  IntegerMatrix result_r = as<IntegerMatrix>(wrap(result));
  result_r.attr("dimnames") = u_names;
  result_r.attr("no_unique") = no_unique;
  return result_r;
}

// [[Rcpp::export]]
List rcpp_get_incoma_matrix_to_list(IntegerMatrix x){
  IntegerVector no_unique = x.attr("no_unique");
  int no_unique_len = no_unique.length();
  int max_x = 0;
  int min_x = 0;
  List result(pow(no_unique_len, 2.0));
  int n = 0;
  for (int i = 0; i < no_unique_len; i++){
    min_x = max_x;
    max_x = max_x + no_unique(i);
    int max_y = 0;
    int min_y = 0;
    for (int j = 0; j < no_unique_len; j++){
      min_y = max_y;
      max_y = max_y + no_unique(j);
      result(n) = x(Range(min_x, max_x - 1), Range(min_y, max_y - 1));

      n++;
    }
  }
  return(result);
}

/*** R
library(raster)
set.seed(10100)
l1 = raster(matrix(sample(1:2, size = 1000000, replace = TRUE), ncol = 1000))
l2 = raster(matrix(sample(c(9, 6, 3), size = 1000000, replace = TRUE), ncol = 1000))
x = stack(l1, l2, l1)
rasters = lapply(raster::as.list(x), raster::as.matrix)
neighbourhood = 4
directions = as.matrix(neighbourhood)
rcpp_get_incoma(rasters, directions)
# profvis::profvis(get_incoma(x))
bench::mark(check = FALSE,
  rcpp_get_incoma(rasters, directions),
            get_incoma(x))
*/
