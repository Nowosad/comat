#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector get_normalized(NumericVector x, std::string normalization) {
  unsigned int len_x = x.length();
  NumericVector y(len_x);
  double sum_x = sum(x);
  if (sum_x != 0){
    if (normalization == "pdf"){
      for (unsigned int i = 0; i < len_x; i++){
        y[i] = x[i] / sum_x;
      }
    }
  }
  return y;
}

/*** R
get_normalized(c(3, 4.5, 2, 1, 0.2), normalization = "pdf")
*/
