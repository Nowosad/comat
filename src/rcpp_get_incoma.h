#ifndef RCPP_GET_INCOMA_H
#define RCPP_GET_INCOMA_H

#include "rcpp_get_coma.h"
#include "rcpp_get_cocoma.h"
#include <RcppArmadillo.h>
using namespace Rcpp;
//[[Rcpp::interfaces(r, cpp)]]

Rcpp::List rcpp_get_incoma(const Rcpp::List x,
                                    const arma::imat directions) ;

Rcpp::List rcpp_get_incoma_list(const Rcpp::List x,
                                const arma::imat directions,
                                Rcpp::List classes) ;

Rcpp::IntegerMatrix rcpp_get_incoma_matrix(const Rcpp::List x) ;

#endif // RCPP_GET_INCOMA_H
