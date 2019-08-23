#include "rcpp_get_wecoma.h"
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::interfaces(r, cpp)]]

//' Wecoma
//'
//' @param x A matrix.
//' @param w A matrix.
//' @param directions A matrix.
//' @param fun "mean", "geometric_mean", or "focal".
//' @param na_action "replace", "omit", "keep"
//' @export
// [[Rcpp::export]]
NumericMatrix rcpp_get_wecoma(const IntegerMatrix x,
                              const NumericMatrix w,
                              const arma::imat directions,
                              const std::string fun,
                              const std::string na_action) {
    const int na = NA_INTEGER;
    const unsigned ncols = x.ncol();
    const unsigned nrows = x.nrow();

    std::vector<int> classes = get_unique_values(x);
    std::map<int, unsigned> class_index = get_class_index_map(classes);

    unsigned n_classes = class_index.size();
    // std::vector<std::vector<unsigned> > cooc_mat(n_classes, std::vector<unsigned>(n_classes));
    // NumericMatrix cooc_mat(n_classes, n_classes);
    NumericMatrix result(n_classes, n_classes);

    // create neighbors coordinates
    IntegerMatrix tmp = create_neighborhood(directions);
    int neigh_len = tmp.nrow();
    std::vector<std::vector<int> > neig_coords;
    for (int row = 0; row < neigh_len; row++) {
        IntegerVector a = tmp.row(row);
        std::vector<int> b(a.begin(), a.end());
        neig_coords.push_back(b);
    }
    // Rcout << "The value of w : " << w << "\n";

    // NAs need an index, otherwise they are counted as neighbors of class[0]
    class_index.insert(std::make_pair(na, n_classes));

    for (unsigned col = 0; col < ncols; col++) {
        for (unsigned row = 0; row < nrows; row++) {
            const int focal_x = x[col * nrows + row];
            if (focal_x == na)
                continue;
            unsigned focal_class = class_index[focal_x];
            double focal_w = w[col * nrows + row];
            if (na_action != "keep" && !arma::is_finite(focal_w)){
                if (na_action == "replace"){
                    focal_w = 0.0;
                } else if (na_action == "omit"){
                    continue;
                }
            }
            for (int h = 0; h < neigh_len; h++) {
                unsigned int neig_col = neig_coords[h][0] + col;
                unsigned int neig_row = neig_coords[h][1] + row;
                if (neig_col >= 0 &&
                        neig_row >= 0 &&
                        neig_col < ncols &&
                        neig_row < nrows) {
                    const int neig_x = x[neig_col * nrows + neig_row];
                    if (neig_x == na)
                        continue;
                    unsigned neig_class = class_index[neig_x];
                    double neig_w = w[neig_col * nrows + neig_row];

                    if (na_action != "keep" && !arma::is_finite(neig_w)){
                        if (na_action == "replace"){
                            neig_w = 0.0;
                        } else if (na_action == "omit"){
                            continue;
                        }
                    }
                    double value = 0.0;
                    if (fun == "mean"){
                        value = ((focal_w + neig_w) / 2.0);
                    } else if (fun == "geometric_mean"){
                        value = sqrt(focal_w * neig_w);
                    } else if (fun == "focal"){
                        value = focal_w;
                    } else {
                        stop("`fun` must be one of: 'mean', 'geometric_mean', or 'focal'.");
                    }
                    // Rcout << "The value of value : " << value << "\n";
                    result(focal_class,neig_class) += value;
                }
            }
        }
    }

    // add names
    List u_names = List::create(classes, classes);
    result.attr("dimnames") = u_names;
    return result;
}

/*** R
library(raster)
x = as.matrix(raster("data-raw/x.tif"))
w = as.matrix(raster("data-raw/w.tif"))
rcpp_get_wecoma(x, w, matrix(4))
rcpp_get_wecoma(x, w, matrix(4), fun = "geometric_mean")
rcpp_get_wecoma(x, w, matrix(4), fun = "focal")
# rcpp_get_wecoma(x, w, matrix(4), fun = "lalal")

x_na = as.matrix(raster("data-raw/x_na.tif"))
w_na = as.matrix(raster("data-raw/w_na.tif"))
rcpp_get_wecoma(x_na, w_na, matrix(4))
rcpp_get_wecoma(x, w_na, matrix(4))
rcpp_get_wecoma(x_na, w, matrix(4))

# a = rcpp_get_wecoma(matrix(sample.int(10, size = 40000, replace = TRUE), ncol = 200), matrix(sample(40000), ncol = 200), matrix(4))
# a
#
#
library(sd)
library(raster)
real_raster = create_realization(perc_raster)
# plot(real_raster)
b = create_weights(real_raster, perc_raster, size = 10)

plot(real_raster)
plot(b)

x2 = as.matrix(real_raster)
w2 = as.matrix(b)
# mode(w2) = "integer"

# x2 = x2[290:300, 60:70]
# w2 = w2[290:300, 60:70]
# mode(w2) = "integer"
wec = rcpp_get_wecoma(x2, w2, as.matrix(4), "mean")
wec
*/
