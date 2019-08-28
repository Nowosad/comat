#' Create a co-occurrence matrix (coma)
#'
#' @param x A RasterLayer with categories
#' @param neighbourhood The number of directions in which cell adjacencies are considered as neighbours:
#' 4 (rook's case) or 8 (queen's case). The default is 4.
#'
#' @return A co-occurrence matrix
#' @export
#'
#' @examples
#' library(comat)
#' library(raster)
#' data(x, package = "comat")
#' plot(x)
#'
#' com = get_coma(x)
#' com
#'
get_coma = function(x, neighbourhood = 4){
  x = raster::as.matrix(x)
  w = raster::as.matrix(w)
  directions = as.matrix(neighbourhood)

  rcpp_get_coma(x, directions)
}
