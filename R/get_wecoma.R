#' Create a weighted cooccurrence matrix (wecoma)
#'
#' @param x A RasterStack with categories
#' @param w A RasterStack with weights
#' @param neighbourhood The number of directions in which cell adjacencies are considered as neighbours:
#' 4 (rook's case) or 8 (queen's case). The default is 4.
#' @param fun "mean", "geometric_mean", or "focal". The default is "mean".
#' @param na_action "replace", "omit", or "keep". The default is "replace".
#'
#' @return A weighted cooccurrence matrix
#' @export
#'
#' @examples
#' library(wecoma)
#' library(raster)
#' data(x, package = "wecoma")
#' data(w, package = "wecoma")
#' plot(x)
#' plot(w)
#'
#' wom = get_wecoma(x, w)
#' plot(wom)
#'
get_wecoma = function(x, w, neighbourhood = 4, fun = "mean", na_action = "replace"){
  x = raster::as.matrix(x)
  w = raster::as.matrix(w)
  directions = as.matrix(neighbourhood)

  rcpp_get_wecoma(x, w, directions, fun, na_action)
}
