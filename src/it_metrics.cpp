#include "it_metrics.h"
using namespace Rcpp;

double rcpp_ent(const NumericMatrix x,
                std::string base){

  NumericVector com_c = colSums(x);
  double comp = rcpp_get_entropy(com_c, base);
  return comp;
}

double rcpp_joinent(const NumericMatrix x,
                    std::string base,
                    bool ordered){

  NumericVector coh = rcpp_get_vec(x, ordered, "none");

  double cplx = rcpp_get_entropy(coh, base);
  return cplx;
}

double rcpp_condent(const NumericMatrix x,
                    std::string base,
                    bool ordered){

  double comp = rcpp_ent(x, base);
  double cplx = rcpp_joinent(x, base, ordered);

  double conf = cplx - comp;
  return conf;
}

double rcpp_mutinf(const NumericMatrix x,
                    std::string base,
                    bool ordered){

  double comp = rcpp_ent(x, base);
  double cplx = rcpp_joinent(x, base, ordered);

  double conf = cplx - comp;
  double aggr = comp - conf;
  return aggr;
}

double rcpp_relmutinf(const NumericMatrix x,
                      std::string base,
                      bool ordered){

  double comp = rcpp_ent(x, base);
  double cplx = rcpp_joinent(x, base, ordered);
  double conf = cplx - comp;
  double aggr = comp - conf;

  double rel;
  if (aggr == 0){
    rel = 1;
  } else {
    rel = aggr / comp;
  }
  return rel;
}

/*** R
a = matrix(sample(1:3, size = 6400, replace = TRUE), nrow = 80)
b = matrix(c(rep(1, 5000), rep(2, 1400)), nrow = 80)

raster::plot(raster::raster(a))
raster::plot(raster::raster(b))

a = rcpp_get_coma(a, directions = matrix(4))
b = rcpp_get_coma(b, directions = matrix(4))

rcpp_ent(a, base = "log2")
rcpp_joinent(a, base = "log2", ordered = TRUE)
rcpp_condent(a, base = "log2", ordered = TRUE)
rcpp_mutinf(a, base = "log2", ordered = FALSE)
rcpp_mutinf(b, base = "log2", ordered = FALSE)
rcpp_relmutinf(a, base = "log2", ordered = FALSE)
rcpp_relmutinf(b, base = "log2", ordered = FALSE)
*/
