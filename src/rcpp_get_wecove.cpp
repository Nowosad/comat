#include "rcpp_get_wecove.h"
// [[Rcpp::interfaces(r, cpp)]]

// [[Rcpp::export]]
NumericVector rcpp_get_wecove(const IntegerMatrix x,
                              const NumericMatrix w,
                              const arma::imat directions,
                              const std::string fun,
                              const std::string na_action,
                              bool ordered) {
  NumericVector result;
  // calculate a coocurrence matrix
  NumericMatrix y = rcpp_get_wecoma(x, w, directions, fun, na_action);
  if (ordered){
    result = as<NumericVector>(wrap(y));
  } else {
    // get a coocurence matrix dimension (it is equal to nrow and ncol)
    int num_e = y.ncol() - 1;
    // Unique combinations number
    int uc = triangular_index(num_e, num_e) + 1;
    // create an empty vector of the unique combinations size
    NumericVector hist(uc);
    // populate a histogram
    for (int i = 0; i <= num_e; i++) {
      for (int j = 0; j <= num_e; j++) {
        hist(triangular_index(i, j)) += y(i, j);
      }
    }
    // every value of neighborhood was calculated twice, therefore divide by 2
    // return a coocurrence vector
    result = as<NumericVector>(wrap(hist / 2));
  }
  // remove a dim attribute
  result.attr("dim") = R_NilValue;
  return result;
}

/***R
library(raster)
x = as.matrix(raster("data-raw/x.tif"))
w = as.matrix(raster("data-raw/w.tif"))
rcpp_get_wecove(x, w, matrix(4), fun = "mean", na_action = "replace", ordered = TRUE)
rcpp_get_wecove(x, w, matrix(4), fun = "mean", na_action = "replace", ordered = FALSE)


x_na = as.matrix(raster("data-raw/x_na.tif"))
w_na = as.matrix(raster("data-raw/w_na.tif"))
rcpp_get_wecove(x_na, w_na, matrix(4), fun = "mean", na_action = "replace", ordered = TRUE)
rcpp_get_wecove(x, w_na, matrix(4), fun = "mean", na_action = "replace", ordered = TRUE)
rcpp_get_wecove(x_na, w, matrix(4), fun = "mean", na_action = "replace", ordered = TRUE)

library(sd)
library(raster)
real_raster = create_realization(perc_raster)
b = create_weights(real_raster, perc_raster, size = 10)

plot(real_raster)
plot(b)

x2 = as.matrix(real_raster)
w2 = as.matrix(b)

wec = rcpp_get_wecove(x2, w2, as.matrix(4), fun = "mean", na_action = "replace", ordered = TRUE)
wec
*/
