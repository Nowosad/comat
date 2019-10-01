#ifndef RCPP_GET_WECOMA_H
#define RCPP_GET_WECOMA_H

#include <RcppArmadillo.h>
using namespace Rcpp;
//[[Rcpp::interfaces(r, cpp)]]

Rcpp::NumericMatrix rcpp_get_wecoma(const Rcpp::IntegerMatrix x,
                                    const Rcpp::NumericMatrix w,
                                    const arma::imat directions,
                                    const std::string fun = "mean",
                                    const std::string na_action = "replace") ;

Rcpp::NumericMatrix rcpp_get_wecoma_internal(const Rcpp::IntegerMatrix x,
                              const Rcpp::NumericMatrix w,
                              const arma::imat directions,
                              std::vector<int> classes,
                              const std::string fun = "mean",
                              const std::string na_action = "replace") ;

#endif // RCPP_GET_WECOMA_H
