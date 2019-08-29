#' Create a co-located co-occurrence matrix (cocoma)
#'
#' @param x A RasterLayer with categories
#' @param y A RasterLayer with categories
#' @param neighbourhood The number of directions in which cell adjacencies are considered as neighbours:
#' 4 (rook's case) or 8 (queen's case). The default is 4.
#'
#' @return A co-located co-occurrence matrix
#' @export
#'
#' @examples
#' library(comat)
#' library(raster)
#' l1 = raster(matrix(sample(1:2, size = 100, replace = TRUE), ncol = 10))
#' l2 = raster(matrix(sample(c(9, 6, 3), size = 100, replace = TRUE), ncol = 10))
#'
#' coom = get_cocoma(l1, l2)
#' coom
#'
get_cocoma = function(x, y, neighbourhood = 4){
  x = raster::as.matrix(x)
  y = raster::as.matrix(y)
  directions = as.matrix(neighbourhood)

  n = rcpp_get_cocoma(x, y, directions)
  structure(n, class = c(class(n), "cocoma"))
}
