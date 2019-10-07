#' Create an integrated co-occurrence matrix (wecoma)
#'
#' @param x A list object containing categorical matrices with categories
#' @param neighbourhood The number of directions in which cell adjacencies are considered as neighbours:
#' 4 (rook's case) or 8 (queen's case). The default is 4.
#'
#' @return An integrated co-occurrence matrix (in form of a list of matrices)
#' @export
#'
#' @examples
#' data(raster_x, package = "comat")
#' data(raster_w, package = "comat")
#' x = list(raster_x, raster_w, raster_x)
#'
#' get_incoma(x)
#'
get_incoma = function(x, neighbourhood = 4){
  directions = as.matrix(neighbourhood)

  n = rcpp_get_incoma(x, directions)
  # rcpp_get_incoma_matrix(n)
  n
}


