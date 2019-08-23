#ifndef RCPP_GET_COCOMA_H
#define RCPP_GET_COCOMA_H

#include "create_neighborhood.h"
#include "get_unique_values.h"
#include "get_class_index_map.h"
#include <RcppArmadillo.h>
using namespace Rcpp;
//[[Rcpp::interfaces(r, cpp)]]

Rcpp::NumericMatrix rcpp_get_cocoma(const Rcpp::IntegerMatrix x,
                                    const Rcpp::IntegerMatrix y,
                                    const arma::imat directions) ;

#endif // RCPP_GET_COCOMA_H
