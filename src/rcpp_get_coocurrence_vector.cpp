#include "traingular_index.h"
#include "rcpp_get_coocurrence_matrix.h"
#include "rcpp_get_coocurrence_vector.h"
// [[Rcpp::interfaces(r, cpp)]]

// [[Rcpp::export]]
NumericVector rcpp_get_coocurrence_vector(IntegerMatrix x, arma::imat directions, bool ordered) {
    NumericVector result;
    // calculate a coocurrence matrix
    IntegerMatrix y = rcpp_get_coocurrence_matrix(x, directions);
    if (ordered){
        result = as<NumericVector>(wrap(y));
    } else {
        // get a coocurence matrix dimension (it is equal to nrow and ncol)
        int num_e = y.ncol() - 1;
        // Unique combinations number
        int uc = triangular_index(num_e, num_e) + 1;
        // create an empty vector of the unique combinations size
        NumericVector hist(uc);
        // populate a histogram
        for (int i = 0; i <= num_e; i++) {
            for (int j = 0; j <= num_e; j++) {
                hist(triangular_index(i, j)) += y(i, j);
            }
        }
        // every value of neighborhood was calculated twice, therefore divide by 2
        // return a coocurrence vector
        result = as<NumericVector>(wrap(hist / 2));
    }
    // remove a dim attribute
    result.attr("dim") = R_NilValue;
    return result;
}
