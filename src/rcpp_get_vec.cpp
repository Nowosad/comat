#include "rcpp_get_vec.h"
// [[Rcpp::interfaces(r, cpp)]]

// [[Rcpp::export]]
NumericVector rcpp_get_vec(NumericMatrix x,
                            bool ordered) {
    NumericVector result;
    // calculate a coocurrence matrix
    if (ordered){
        NumericMatrix x2 = clone(x);
        result = as<NumericVector>(wrap(x2));
    } else {
        // get a coocurence matrix dimension (it is equal to nrow and ncol)
        int num_e = x.ncol() - 1;
        // Unique combinations number
        int uc = triangular_index(num_e, num_e) + 1;
        // create an empty vector of the unique combinations size
        NumericVector hist(uc);
        // populate a histogram
        for (int i = 0; i <= num_e; i++) {
            for (int j = 0; j <= num_e; j++) {
                hist(triangular_index(i, j)) += x(i, j);
            }
        }
        // every value of neighborhood was calculated twice, therefore divide by 2
        // return a coocurrence vector
        result = as<NumericVector>(wrap(hist / 2));
    }
    // remove a dim attribute
    result.attr("dim") = R_NilValue;
    //result.attr("names")
    return result;
}

// [[Rcpp::export]]
NumericVector rcpp_get_wecove(NumericMatrix x,
                           bool ordered) {

    return rcpp_get_vec(x, ordered);
}
