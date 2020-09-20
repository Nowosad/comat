#ifndef GET_ENTROPY_H
#define GET_ENTROPY_H
#include <RcppArmadillo.h>
// [[Rcpp::interfaces(r, cpp)]]

// [[Rcpp::export]]
double rcpp_get_entropy(const Rcpp::NumericVector x, std::string base = "log2");

#endif // GET_ENTROPY_H
