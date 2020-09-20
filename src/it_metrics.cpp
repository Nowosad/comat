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
