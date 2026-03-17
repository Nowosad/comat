#include "rcpp_get_cocoma.h"
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::interfaces(r, cpp)]]

using namespace Rcpp;
// [[Rcpp::export]]
IntegerMatrix rcpp_get_cocoma(const IntegerMatrix x,
                              const IntegerMatrix y,
                              const arma::imat directions){
    std::vector<int> classes_x = get_unique_values(x);
    std::vector<int> classes_y = get_unique_values(y);
    IntegerMatrix result = rcpp_get_cocoma_internal(x, y, directions, classes_x, classes_y);
    return result;
}

// [[Rcpp::export]]
IntegerMatrix rcpp_get_cocoma_internal(const IntegerMatrix x,
                              const IntegerMatrix y,
                              const arma::imat directions,
                              std::vector<int> classes_x,
                              std::vector<int> classes_y) {

    const unsigned ncols = x.ncol();
    const unsigned nrows = x.nrow();

    const std::map<int, unsigned> class_index_x = get_class_index_map(classes_x);
    unsigned n_classes_x = class_index_x.size();

    const std::map<int, unsigned> class_index_y = get_class_index_map(classes_y);
    unsigned n_classes_y = class_index_y.size();

    IntegerMatrix result(n_classes_x, n_classes_y);

    // create neighbors coordinates
    IntegerMatrix neigh_coords = create_neighborhood(directions);
    int neigh_len = neigh_coords.nrow();

    for (unsigned col = 0; col < ncols; col++) {
        for (unsigned row = 0; row < nrows; row++) {
            const int focal_x = x[col * nrows + row];
            const auto focal_it = class_index_x.find(focal_x);
            if (focal_it == class_index_x.end())
                continue;
            unsigned focal_class = focal_it->second;
            //const int focal_y = y[col * nrows + row];
            //if (focal_y == na)
            //    continue;
            for (int h = 0; h < neigh_len; h++) {
                int neig_col = neigh_coords(h, 0) + static_cast<int>(col);
                int neig_row = neigh_coords(h, 1) + static_cast<int>(row);
                if (neig_col >= 0 &&
                    neig_row >= 0 &&
                    neig_col < static_cast<int>(ncols) &&
                    neig_row < static_cast<int>(nrows)) {
                    const int neig_y = y[neig_col * nrows + neig_row];
                    const auto neigh_it = class_index_y.find(neig_y);
                    if (neigh_it == class_index_y.end())
                        continue;
                    unsigned neig_class = neigh_it->second;

                    result(focal_class,neig_class)++;
                }
            }
        }
    }

    // add names
    List u_names = List::create(classes_x, classes_y);
    result.attr("dimnames") = u_names;
    return result;
}

/*** R
library(raster)
set.seed(2019-08-15)
l1 = matrix(sample(1:2, size = 100, replace = TRUE), ncol = 10)
l2 = matrix(sample(c(9, 6, 3), size = 100, replace = TRUE), ncol = 10)

rcpp_get_cocoma(l1, l2, matrix(4))
*/
