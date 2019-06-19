#include "traingular_index.h"

// [[Rcpp::export]]
int triangular_index(int r, int c) {
  r++;
  c++;
  if (c <= r){
    return (r - 1) * r / 2 + c - 1;
  } else {
    return (c - 1) * c / 2 + r - 1;
  }
}
