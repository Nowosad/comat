#' Create a weighted cooccurrence vector (wecove)
#'
#' Converts a weighted cooccurrence matrix (wecoma) to
#' a weighted cooccurrence vector (wecove)
#'
#' @param x A RasterStack - an output of the [get_wecoma()] function
#' @param ordered The type of pairs considered.
#' Either ordered (TRUE) or unordered (FALSE).
#' The default is TRUE.
#'
#' @return A weighted cooccurrence vector
#' @export
#'
#' @examples
#' library(wecoma)
#' library(raster)
#' data(x, package = "wecoma")
#' data(w, package = "wecoma")
#'
#' wom = get_wecoma(x, w)
#' plot(wom)
#' wom
#'
#' wov = get_wecove(wom)
#' wov
get_wecove = function(x, ordered = TRUE){
  x = raster::as.matrix(x)
  rcpp_get_wecove(x, ordered)
}
