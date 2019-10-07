#' Create a weighted co-occurrence matrix (wecoma)
#'
#' @param x A matrix with categories
#' @param w A matrix with weights
#' @param neighbourhood The number of directions in which cell adjacencies are considered as neighbours:
#' 4 (rook's case) or 8 (queen's case). The default is 4.
#' @param fun "mean", "geometric_mean", or "focal". The default is "mean".
#' @param na_action "replace", "omit", or "keep". The default is "replace".
#'
#' @return A weighted co-occurrence matrix
#' @export
#'
#' @examples
#' library(comat)
#' data(raster_x, package = "comat")
#' data(raster_w, package = "comat")
#'
#' wom = get_wecoma(raster_x, raster_w)
#' wom
#'
get_wecoma = function(x, w, neighbourhood = 4, fun = "mean", na_action = "replace"){
  directions = as.matrix(neighbourhood)

  rcpp_get_wecoma(x, w, directions, fun, na_action)
}
