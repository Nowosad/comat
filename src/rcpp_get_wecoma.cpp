#include "rcpp_get_wecoma.h"
#include "rcpp_get_coma.h"
#include "create_neighborhood.h"
#include "get_unique_values.h"
#include "get_class_index_map.h"
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::interfaces(r, cpp)]]

// [[Rcpp::export]]
NumericMatrix rcpp_get_wecoma(const IntegerMatrix& x,
                              const NumericMatrix& w,
                              const arma::imat& directions,
                              const std::string fun,
                              const std::string na_action) {
    std::vector<int> classes = get_unique_values(x);
    NumericMatrix result = rcpp_get_wecoma_internal(x, w, directions, classes, fun, na_action);
    return result;
}

// [[Rcpp::export]]
NumericMatrix rcpp_get_wecoma_internal(const IntegerMatrix& x,
                                       const NumericMatrix& w,
                              const arma::imat& directions,
                              const std::vector<int>& classes,
                              const std::string fun,
                              const std::string na_action) {

    const unsigned ncols = x.ncol();
    const unsigned nrows = x.nrow();

    const std::map<int, unsigned> class_index = get_class_index_map(classes);
    unsigned n_classes = class_index.size();
    // std::vector<std::vector<unsigned> > cooc_mat(n_classes, std::vector<unsigned>(n_classes));
    // NumericMatrix cooc_mat(n_classes, n_classes);
    NumericMatrix result(n_classes, n_classes);

    // create neighbors coordinates
    IntegerMatrix neigh_coords = create_neighborhood(directions);
    int neigh_len = neigh_coords.nrow();

    const int fun_mode =
        fun == "mean" ? 0 :
        fun == "geometric_mean" ? 1 :
        fun == "focal" ? 2 : -1;

    const int na_mode =
        na_action == "keep" ? 0 :
        na_action == "replace" ? 1 :
        na_action == "omit" ? 2 : -1;

    if (fun_mode < 0) {
        stop("`fun` must be one of: 'mean', 'geometric_mean', or 'focal'.");
    }

    for (unsigned col = 0; col < ncols; col++) {
        for (unsigned row = 0; row < nrows; row++) {
            const int focal_x = x[col * nrows + row];
            const auto focal_it = class_index.find(focal_x);
            if (focal_it == class_index.end())
                continue;
            unsigned focal_class = focal_it->second;
            double focal_w = w[col * nrows + row];
            if (na_mode != 0 && !std::isfinite(focal_w)){
                if (na_mode == 1){
                    focal_w = 0.0;
                } else if (na_mode == 2){
                    continue;
                }
            }
            for (int h = 0; h < neigh_len; h++) {
                int neig_col = neigh_coords(h, 0) + static_cast<int>(col);
                int neig_row = neigh_coords(h, 1) + static_cast<int>(row);
                if (neig_col >= 0 &&
                        neig_row >= 0 &&
                        neig_col < static_cast<int>(ncols) &&
                        neig_row < static_cast<int>(nrows)) {
                    const int neig_x = x[neig_col * nrows + neig_row];
                    const auto neigh_it = class_index.find(neig_x);
                    if (neigh_it == class_index.end())
                        continue;
                    unsigned neig_class = neigh_it->second;
                    double neig_w = w[neig_col * nrows + neig_row];

                    if (na_mode != 0 && !std::isfinite(neig_w)){
                        if (na_mode == 1){
                            neig_w = 0.0;
                        } else if (na_mode == 2){
                            continue;
                        }
                    }
                    double value = 0.0;
                    if (fun_mode == 0){
                        value = ((focal_w + neig_w) / 2.0);
                    } else if (fun_mode == 1){
                        value = sqrt(focal_w * neig_w);
                    } else {
                        value = focal_w;
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
