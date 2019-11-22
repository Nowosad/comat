#ifndef GET_COMA_H
#define GET_COMA_H
#include <RcppArmadillo.h>
#include "create_neighborhood.h"
#include "get_unique_values.h"
#include "get_class_index_map.h"
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]

IntegerMatrix rcpp_get_coma(const IntegerMatrix& x,
                            const arma::imat directions);

IntegerMatrix rcpp_get_coma_internal(const IntegerMatrix& x,
                            const arma::imat directions,
                            std::vector<int> classes = std::vector<int>(0));
#endif // GET_COMA_H
