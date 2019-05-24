#ifndef RCPP_GET_WECOMA_H
#define RCPP_GET_WECOMA_H
#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]

IntegerMatrix rcpp_get_wecoma(const IntegerMatrix x,
                              const IntegerMatrix w,
                              const arma::imat directions);

#endif // RCPP_GET_WECOMA_H
