#ifndef RCPP_GET_INCOMA_H
#define RCPP_GET_INCOMA_H

#include "rcpp_get_coma.h"
#include "rcpp_get_cocoma.h"
#include <RcppArmadillo.h>
using namespace Rcpp;
//[[Rcpp::interfaces(r, cpp)]]

Rcpp::IntegerMatrix rcpp_get_incoma(const Rcpp::IntegerMatrix x,
                                    const arma::imat directions) ;

#endif // RCPP_GET_INCOMA_H
