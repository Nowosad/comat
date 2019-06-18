#ifndef RCPP_GET_WECOMA_H
#define RCPP_GET_WECOMA_H
#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]

//' Wecoma
//'
//' @param x A matrix.
//' @param w A matrix.
//' @param directions A matrix.
//' @param fun "mean", "geometric_mean", or "focal".
//' @param na_action "replace", "omit", "keep"
//' @export
// [[Rcpp::export]]
NumericMatrix rcpp_get_wecoma(const IntegerMatrix x,
                              const NumericMatrix w,
                              const arma::imat directions,
                              const std::string fun = "mean",
                              const std::string na_action = "replace") ;

#endif // RCPP_GET_WECOMA_H
