#' Create a weighted cooccurrence vector (wecove)
#'
#' Converts a weighted cooccurrence matrix (wecoma) to
#' a weighted cooccurrence vector (wecove)
#'
#' @param x A RasterStack
#' @param ordered The type of pairs considered.
#' Either ordered (TRUE) or unordered (FALSE).
#' The default is TRUE.
#'
#' @return A RasterStack
#' @export
#'
get_wecove = function(x, ordered = TRUE){
  x = raster::as.matrix(x)
  rcpp_get_wecove(x, ordered)
}
