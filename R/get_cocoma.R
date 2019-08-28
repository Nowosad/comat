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
#' data(x, package = "comat")
#' data(x_na, package = "comat")
#' plot(x)
#' plot(x_na)
#'
#' coom = get_cocoma(x, x_na)
#' coom
#'
get_cocoma = function(x, y, neighbourhood = 4){
  x = raster::as.matrix(x)
  y = raster::as.matrix(y)
  directions = as.matrix(neighbourhood)

  rcpp_get_cocoma(x, y, directions)
}
