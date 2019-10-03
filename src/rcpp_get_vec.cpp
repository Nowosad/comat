#include "rcpp_get_vec.h"
#include "get_unique_values.h"
// [[Rcpp::interfaces(r, cpp)]]
// [[Rcpp::plugins(cpp11)]]

// [[Rcpp::export]]
NumericVector rcpp_get_vec(NumericMatrix x,
                           bool ordered,
                           std::string normalization) {
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
    // normalize the output vector
    result = get_normalized(result, normalization);
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

// [[Rcpp::export]]
IntegerVector is_cross_mat(int n_layers){
    IntegerVector result(pow(n_layers, 2));
    result(0) = 1;
    int zero_index = 1;
    for (int i = 1; i < result.length(); i++){
        if(zero_index == 0){
            result(i) = 1;
        } else {
            result(i) = 0;
        }
        zero_index ++;
        if (zero_index > n_layers){
            zero_index = 0;
        }
    }
    return result;
}

// [[Rcpp::export]]
NumericVector rcpp_get_incove(List x,
                              std::string ordered,
                              std::string normalization) {
    int x_len = x.length();

    // Figure out the length of the output vector
    std::size_t total_length = 0;
    for (std::size_t i = 0; i < x_len; ++i){
        total_length += Rf_length(x[i]);
    }
    NumericVector result(total_length);

    // calculate a coocurrence matrix
    if (ordered == "A"){
        std::size_t index = 0;
        for (int i = 0; i < x_len; i++){
            IntegerMatrix x_i = x[i];
            // NumericVector x_iv = as<NumericVector>(wrap(x_i));
            NumericMatrix x_iv1 = as<NumericMatrix>(x_i);

            NumericVector x_iv = rcpp_get_vec(x_iv1, true, normalization);
            std::copy(x_iv.begin(), x_iv.end(), result.begin() + index);
            // Update the index
            index += x_iv.size();
        }
    } else if (ordered == "B"){
        IntegerVector cros_mat_id = is_cross_mat(sqrt(x_len));

        std::size_t index = 0;
        for (int i = 0; i < x_len; i++){
            IntegerMatrix x_i = x[i];
            // NumericVector x_iv = as<NumericVector>(wrap(x_i));
            NumericMatrix x_iv1 = as<NumericMatrix>(x_i);
            NumericVector x_iv;
            if(cros_mat_id(i) == 1){
                x_iv = rcpp_get_vec(x_iv1, false, normalization);
            } else {
                x_iv = rcpp_get_vec(x_iv1, true, normalization);
            }
            // Rcout << "The value of x_iv : " << x_iv << "\n";

            std::copy(x_iv.begin(), x_iv.end(), result.begin() + index);
            // Update the index
            index += x_iv.size();
            // Rcout << "The value of index : " << index << "\n";

        }
        result = result[Rcpp::Range(0, index - 1)];
    } else if (ordered == "C"){
        IntegerVector cros_mat_id = is_cross_mat(sqrt(x_len));

        IntegerVector id;
        for (int i = 0; i < sqrt(x_len); i++){
            for (int j = 0; j < sqrt(x_len); j++){
                id.push_back(((i + 1) * (j + 1)) - 1);
            }
        }
        // Rcout << "The value of id : " << id << "\n";
        id = sort_unique(id);
        // Rcout << "The value of id : " << id << "\n";

        x = x[id];
        cros_mat_id = cros_mat_id[id];
        x_len = x.length();
        std::size_t index = 0;
        for (int i = 0; i < x_len; i++){
            IntegerMatrix x_i = x[i];
            NumericMatrix x_iv1 = as<NumericMatrix>(x_i);
            NumericVector x_iv;
            if(cros_mat_id(i) == 1){
                x_iv = rcpp_get_vec(x_iv1, false, normalization);
            } else {
                x_iv = rcpp_get_vec(x_iv1, true, normalization);
            }
            std::copy(x_iv.begin(), x_iv.end(), result.begin() + index);
            // Update the index
            index += x_iv.size();
        }
        result = result[Rcpp::Range(0, index - 1)];
    }

    // remove a dim attribute
    result.attr("dim") = R_NilValue;
    //result.attr("names")
    return result;
}

/***R
library(raster)
set.seed(2019-08-23)
l1 = raster(matrix(sample(1:2, size = 100, replace = TRUE), ncol = 10))
l2 = raster(matrix(sample(c(9, 6, 3), size = 100, replace = TRUE), ncol = 10))
l3 = raster(matrix(sample(c(8, 5, 4), size = 100, replace = TRUE), ncol = 10))

x = stack(l1, l2)

p1 = comat:::rcpp_get_incoma(lapply(as.list(x), raster::as.matrix), matrix(4))
rcpp_get_vec(as.matrix(p1), ordered = TRUE, normalization = "none")
rcpp_get_vec(as.matrix(p1), ordered = FALSE, normalization = "none")

rcpp_get_incove(p1, ordered = "A", normalization = "none")
rcpp_get_incove(p1, ordered = "A", normalization = "pdf")
rcpp_get_incove(p1, ordered = "B", normalization = "none")
rcpp_get_incove(p1, ordered = "B", normalization = "pdf")
rcpp_get_incove(p1, ordered = "C", normalization = "none")
rcpp_get_incove(p1, ordered = "C", normalization = "pdf")

is_cross_mat(5)

r1 = comat:::rcpp_get_incoma(lapply(as.list(x), raster::as.matrix), matrix(4))
rcpp_get_incove(r1, ordered = TRUE, normalization = "none")
*/
