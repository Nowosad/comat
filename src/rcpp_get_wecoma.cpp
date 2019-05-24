#include "rcpp_get_coocurrence_matrix.h"
#include "rcpp_create_neighborhood.h"
#include "rcpp_get_unique_values.h"
#include "get_class_index_map.h"

// [[Rcpp::export]]
NumericMatrix rcpp_get_wecoma(const IntegerMatrix x,
                              const NumericMatrix w,
                              const arma::imat directions) {
    const int na = NA_INTEGER;
    const unsigned ncols = x.ncol();
    const unsigned nrows = x.nrow();

    std::vector<int> classes = rcpp_get_unique_values(x);
    std::map<int, unsigned> class_index = get_class_index_map(classes);

    unsigned n_classes = class_index.size();
    // std::vector<std::vector<unsigned> > cooc_mat(n_classes, std::vector<unsigned>(n_classes));
    // NumericMatrix cooc_mat(n_classes, n_classes);
    NumericMatrix result(n_classes, n_classes);
    

    // create neighbors coordinates
    IntegerMatrix tmp = rcpp_create_neighborhood(directions);
    int neigh_len = tmp.nrow();
    std::vector<std::vector<int> > neig_coords;
    for (int row = 0; row < neigh_len; row++) {
        IntegerVector a = tmp.row(row);
        std::vector<int> b(a.begin(), a.end());
        neig_coords.push_back(b);
    }

    // NAs need an index, otherwise they are counted as neighbors of class[0]
    class_index.insert(std::make_pair(na, n_classes));

    for (unsigned col = 0; col < ncols; col++) {
        for (unsigned row = 0; row < nrows; row++) {
            const int focal_x = x[col * nrows + row];
            // Rcout << "The value of tmp : " << tmp << "\n";
            if (focal_x == na)
                continue;
            unsigned focal_class = class_index[focal_x];
            // Rcout << "The value of focal_class : " << focal_class << "\n";
            const double focal_w = w[col * nrows + row];
            // Rcout << "The value of focal_weight : " << focal_weight << "\n";
            for (int h = 0; h < neigh_len; h++) {
                int neig_col = neig_coords[h][0] + col;
                int neig_row = neig_coords[h][1] + row;
                if (neig_col >= 0 &&
                        neig_row >= 0 &&
                        neig_col < ncols &&
                        neig_row < nrows) {
                    const int neig_x = x[neig_col * nrows + neig_row];
                    if (neig_x == na)
                        continue;
                    unsigned neig_class = class_index[neig_x];
                    const double neig_w = w[neig_col * nrows + neig_row];
                    
                    // Rcout << "The value of neig_class : " << neig_class << "\n";
                    double value = ((focal_w + neig_w) / 2.0);
                    // Rcout << "The value of value : " << value << "\n";
                    result(focal_class,neig_class) += value;
                    // cooc_mat[focal_class][neig_class]++;
                    // Rcout << "The value of cooc_mat : " << cooc_mat << "\n";
                }
            }
        }
    }

    // NumericMatrix result(n_classes, n_classes);
    // for (unsigned col = 0; col < cooc_mat.nrow(); col++) {
    //     for (unsigned row = 0; row < cooc_mat.ncol(); row++) {
    //         result(col, row) = cooc_mat(col, row);
    //     }
    // }

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
*/
