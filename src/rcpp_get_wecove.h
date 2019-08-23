#ifndef RCPP_GET_WECOVE_H
#define RCPP_GET_WECOVE_H

#include "rcpp_get_wecoma.h"
#include "triangular_index.h"
#include <RcppArmadillo.h>
using namespace Rcpp;

Rcpp::NumericVector rcpp_get_wecove(const Rcpp::NumericMatrix x,
                                    bool ordered);

#endif // RCPP_GET_WECOVE_H
