#include "rcpp_get_cocoma.h"
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::interfaces(r, cpp)]]

using namespace Rcpp;
// [[Rcpp::export]]
IntegerMatrix rcpp_get_cocoma(const IntegerMatrix x,
                              const IntegerMatrix y,
                              const arma::imat directions) {

    const int na = NA_INTEGER;
    const unsigned ncols = x.ncol();
    const unsigned nrows = x.nrow();

    std::vector<int> classes_x = get_unique_values(x);
    std::map<int, unsigned> class_index_x = get_class_index_map(classes_x);
    unsigned n_classes_x = class_index_x.size();
    // NAs need an index, otherwise they are counted as neighbors of class[0]
    class_index_x.insert(std::make_pair(na, n_classes_x));

    std::vector<int> classes_y = get_unique_values(y);
    std::map<int, unsigned> class_index_y = get_class_index_map(classes_y);
    unsigned n_classes_y = class_index_y.size();
    // NAs need an index, otherwise they are counted as neighbors of class[0]
    class_index_y.insert(std::make_pair(na, n_classes_y));

    IntegerMatrix result(n_classes_x, n_classes_y);

    // create neighbors coordinates
    IntegerMatrix tmp = create_neighborhood(directions);
    int neigh_len = tmp.nrow();
    std::vector<std::vector<int> > neig_coords;
    for (int row = 0; row < neigh_len; row++) {
        IntegerVector a = tmp.row(row);
        std::vector<int> b(a.begin(), a.end());
        neig_coords.push_back(b);
    }

    for (unsigned col = 0; col < ncols; col++) {
        for (unsigned row = 0; row < nrows; row++) {
            const int focal_x = x[col * nrows + row];
            if (focal_x == na)
                continue;
            unsigned focal_class = class_index_x[focal_x];
            //const int focal_y = y[col * nrows + row];
            //if (focal_y == na)
            //    continue;
            for (int h = 0; h < neigh_len; h++) {
                unsigned int neig_col = neig_coords[h][0] + col;
                unsigned int neig_row = neig_coords[h][1] + row;
                if (neig_col >= 0 &&
                    neig_row >= 0 &&
                    neig_col < ncols &&
                    neig_row < nrows) {
                    const int neig_y = y[neig_col * nrows + neig_row];
                    if (neig_y == na)
                        continue;
                    unsigned neig_class = class_index_y[neig_y];

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
