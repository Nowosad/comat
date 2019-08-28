#ifndef GET_VEC_H
#define GET_VEC_H
#include <RcppArmadillo.h>
#include "triangular_index.h"
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]

NumericVector rcpp_get_vec(NumericMatrix x, bool ordered = true);

#endif // GET_VEC_H
