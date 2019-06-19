#ifndef RCPP_GET_WECOVE_H
#define RCPP_GET_WECOVE_H

#include "rcpp_get_wecoma.h"
#include "traingular_index.h"
#include <RcppArmadillo.h>
using namespace Rcpp;

Rcpp::NumericVector rcpp_get_wecove(const Rcpp::IntegerMatrix x,
                              const Rcpp::NumericMatrix w,
                              const arma::imat directions,
                              const std::string fun = "mean",
                              const std::string na_action = "replace",
                              bool ordered = TRUE);

#endif // RCPP_GET_WECOVE_H
