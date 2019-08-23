#ifndef GET_COVE_H
#define GET_COVE_H
#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]

NumericVector rcpp_get_cove(IntegerMatrix x, bool ordered = true);

#endif // GET_COVE_H
