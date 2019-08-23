#ifndef CREATE_NEIGHBORHOOD_H
#define CREATE_NEIGHBORHOOD_H
#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]

IntegerMatrix create_neighborhood(arma::imat directions);

#endif // CREATE_NEIGHBORHOOD_H
