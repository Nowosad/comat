#ifndef RCPP_GET_WECOMA_H
#define RCPP_GET_WECOMA_H

#include "rcpp_get_coma.h"
#include "create_neighborhood.h"
#include "get_unique_values.h"
#include "get_class_index_map.h"
#include <RcppArmadillo.h>
using namespace Rcpp;
//[[Rcpp::interfaces(r, cpp)]]

Rcpp::NumericMatrix rcpp_get_wecoma(const Rcpp::IntegerMatrix x,
                              const Rcpp::NumericMatrix w,
                              const arma::imat directions,
                              const std::string fun = "mean",
                              const std::string na_action = "replace") ;

#endif // RCPP_GET_WECOMA_H
