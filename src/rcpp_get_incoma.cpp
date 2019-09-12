#include "rcpp_get_incoma.h"
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::interfaces(r, cpp)]]

// [[Rcpp::export]]
IntegerMatrix rcpp_get_incoma(const List x,
                     const arma::imat directions) {

  int v1_len = x.length();
  List mat_list(v1_len * v1_len);

  int loop = 0;
  for (int i = 0; i < v1_len; i++){
    for (int j = 0; j < v1_len; j++){
      if (i == j){
        mat_list[loop] = rcpp_get_coma(x[i], directions);
      } else {
        mat_list[loop] = rcpp_get_cocoma(x[i], x[j], directions);
      }
      loop ++;
    }
  }

  int mat_len = 0;
  CharacterVector classes_xy;
  for (int k = 0; k < v1_len; k++){
    IntegerMatrix mat_list_k = mat_list[k];
    mat_len = mat_len + mat_list_k.ncol();
    CharacterVector col_names_k = colnames(mat_list_k);
    for (int kka = 0; kka < col_names_k.length(); kka++){
      classes_xy.push_back(col_names_k(kka));
    }
  }

  arma::imat result(0, mat_len);
  int o = 0;
  for (int ii = 0; ii < v1_len; ii++){
    arma::imat x_o = as<arma::imat>(mat_list[o]);
    arma::imat m(x_o.n_rows, 0);
    for (int jj = 0; jj < v1_len; jj++){
      m = arma::join_rows(m, as<arma::imat>(mat_list(o)));
      o = o + 1;
    }
    result = arma::join_cols(result, m);
  }

  // add names
  List u_names = List::create(classes_xy, classes_xy);
  IntegerMatrix result_r = as<IntegerMatrix>(wrap(result));
  result_r.attr("dimnames") = u_names;
  return result_r;
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
