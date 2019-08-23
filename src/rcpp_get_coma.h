#ifndef GET_COMA_H
#define GET_COMA_H
#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]

IntegerMatrix rcpp_get_coma(const IntegerMatrix x,
                            const arma::imat directions);
#endif // GET_COMA_H
