#' Create a co-located co-occurrence matrix (cocoma)
#'
#' @param x A matrix with categories
#' @param y A matrix with categories
#' @param neighbourhood The number of directions in which cell adjacencies are considered as neighbours:
#' 4 (rook's case) or 8 (queen's case). The default is 4.
#'
#' @return A co-located co-occurrence matrix
#' @export
#'
#' @examples
#' library(comat)
#' library(raster)
#' l1 = matrix(sample(1:2, size = 100, replace = TRUE), ncol = 10)
#' l2 = matrix(sample(c(9, 6, 3), size = 100, replace = TRUE), ncol = 10)
#'
#' coom = get_cocoma(l1, l2)
#' coom
#'
get_cocoma = function(x, y, neighbourhood = 4){
  directions = as.matrix(neighbourhood)

  rcpp_get_cocoma(x, y, directions)
}
