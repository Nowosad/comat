#ifndef RCPP_GET_INCOMA_H
#define RCPP_GET_INCOMA_H

#include "rcpp_get_coma.h"
#include "rcpp_get_cocoma.h"
#include <RcppArmadillo.h>
using namespace Rcpp;
//[[Rcpp::interfaces(r, cpp)]]

Rcpp::IntegerMatrix rcpp_get_incoma(const Rcpp::List x,
                                    const arma::imat directions) ;

Rcpp::IntegerMatrix rcpp_get_incoma_internal(const Rcpp::List x,
                                    const arma::imat directions,
                                    Rcpp::List classes) ;

#endif // RCPP_GET_INCOMA_H
