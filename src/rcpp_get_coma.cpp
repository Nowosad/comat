#include "rcpp_get_coma.h"
// [[Rcpp::interfaces(r, cpp)]]

// [[Rcpp::export]]
IntegerMatrix rcpp_get_coma(const IntegerMatrix& x,
                            const arma::imat& directions){
    std::vector<int> classes = get_unique_values(x);
    IntegerMatrix result = rcpp_get_coma_internal(x, directions, classes);
    return result;
}

// [[Rcpp::export]]
IntegerMatrix rcpp_get_coma_internal(const IntegerMatrix& x,
                            const arma::imat& directions,
                            const std::vector<int>& classes) {

    const unsigned ncols = x.ncol();
    const unsigned nrows = x.nrow();

    const std::map<int, unsigned> class_index = get_class_index_map(classes);

    unsigned n_classes = class_index.size();
    std::vector<std::vector<unsigned> > cooc_mat(n_classes,
                                                 std::vector<unsigned>(n_classes));

    // create neighbors coordinates
    IntegerMatrix neigh_coords = create_neighborhood(directions);
    int neigh_len = neigh_coords.nrow();

    for (unsigned col = 0; col < ncols; col++) {
        for (unsigned row = 0; row < nrows; row++) {
            const int value = x[col * nrows + row];
            const auto focal_it = class_index.find(value);
            if (focal_it == class_index.end())
                continue;

            // for (auto& t : class_index_const){
            //     Rcout << t.first << " "
            //           << t.second << "\n";
            // }

            unsigned focal_class = focal_it->second;

            for (int h = 0; h < neigh_len; h++) {
                int neig_col = neigh_coords(h, 0) + static_cast<int>(col);
                int neig_row = neigh_coords(h, 1) + static_cast<int>(row);
                if (neig_col >= 0 &&
                        neig_row >= 0 &&
                        neig_col < static_cast<int>(ncols) &&
                        neig_row < static_cast<int>(nrows)) {
                    const int neigh_value = x[neig_col * nrows + neig_row];
                    const auto neigh_it = class_index.find(neigh_value);
                    if (neigh_it == class_index.end())
                        continue;
                    unsigned neig_class = neigh_it->second;
                    cooc_mat[focal_class][neig_class]++;
                }
            }
        }
    }

    IntegerMatrix result(n_classes, n_classes);
    for (unsigned col = 0; col < cooc_mat.size(); col++) {
        for (unsigned row = 0; row < cooc_mat[col].size(); row++) {
            result(col, row) = cooc_mat[col][row];
        }
    }

    // Rcout << "The value of cooc_mat : " << cooc_mat << "\n";
    // Rcout << "The value of result : " << result << "\n";

    // add names
    List u_names = List::create(classes, classes);
    result.attr("dimnames") = u_names;
    return result;
}

/*** R
library(raster)
library(dplyr)
test = landscapemetrics::augusta_nlcd
mat = raster::as.matrix(test)
four = as.matrix(4)
r = rcpp_get_coma(mat, four)

set.seed(2019-08-23)
mat = matrix(sample(1:2, size = 1000000, replace = TRUE), ncol = 1000)
r = rcpp_get_coma(mat, four)
r = rcpp_get_coma2(mat, four)

bench::mark(rcpp_get_coma(mat, four),
            rcpp_get_coma2(mat, four))
*/
