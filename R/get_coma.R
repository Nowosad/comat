#' Create a co-occurrence matrix (coma)
#'
#' @param x A matrix with categories
#' @param neighbourhood The number of directions in which cell adjacencies are considered as neighbours:
#' 4 (rook's case) or 8 (queen's case). The default is 4.
#'
#' @return A co-occurrence matrix
#' @export
#'
#' @examples
#' library(comat)
#' data(raster_x, package = "comat")
#'
#' com = get_coma(raster_x)
#' com
#'
get_coma = function(x, neighbourhood = 4){
  directions = as.matrix(neighbourhood)

  rcpp_get_coma(x, directions)
}
