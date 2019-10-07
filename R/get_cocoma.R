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
#' data(raster_x, package = "comat")
#' data(raster_x_na, package = "comat")
#'
#' coom = get_cocoma(raster_x, raster_x_na)
#' coom
#'
get_cocoma = function(x, y, neighbourhood = 4){
  directions = as.matrix(neighbourhood)

  rcpp_get_cocoma(x, y, directions)
}
