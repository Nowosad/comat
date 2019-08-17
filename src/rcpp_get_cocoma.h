#ifndef RCPP_GET_COCOMA_H
#define RCPP_GET_COCOMA_H

#include "rcpp_create_neighborhood.h"
#include "rcpp_get_unique_values.h"
#include "get_class_index_map.h"
#include <RcppArmadillo.h>
using namespace Rcpp;
//[[Rcpp::interfaces(r, cpp)]]

Rcpp::NumericMatrix rcpp_get_cocoma(const Rcpp::IntegerMatrix x,
                                    const Rcpp::IntegerMatrix y,
                                    const arma::imat directions) ;

#endif // RCPP_GET_COCOMA_H
