#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector get_normalized(NumericVector &x, std::string normalization) {
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
# get_normalized2 = function(x, normalization){
#   sum_x = sum(x)
#   if (sum_x == 0){
#     return(rep(0, length(x)))
#   } else if (normalization == "pdf"){
#     return(x/sum_x)
#   }
# }
# bench::mark(
#   get_normalized(c(3, 4.5, 2, 1, 0.2), normalization = "pdf"),
#   get_normalized2(c(3, 4.5, 2, 1, 0.2), normalization = "pdf")
# )
*/
