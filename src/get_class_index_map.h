#ifndef GET_CLASS_INDEX_MAP_H
#define GET_CLASS_INDEX_MAP_H
#include <vector>
#include <map>
//[[Rcpp::interfaces(r, cpp)]]

std::map<int, unsigned> get_class_index_map(const std::vector<int> &classes);
#endif // GET_CLASS_INDEX_MAP_H
