#' Create a weighted co-occurrence vector (wecove)
#'
#' Converts a weighted co-occurrence matrix (wecoma) to
#' a weighted co-occurrence vector (wecove)
#'
#' @param x A matrix - an output of the [get_wecoma()] function
#' @param ordered The type of pairs considered.
#' Either "ordered" (TRUE) or "unordered" (FALSE).
#' The default is TRUE.
#' @param normalization Should the output vector be normalized?
#' Either "none" or "pdf".
#' The "pdf" option normalizes a vector to sum to one.
#' The default is "none".
#'
#' @return A weighted co-occurrence vector
#' @export
#'
#' @examples
#' library(comat)
#' library(raster)
#' data(raster_x, package = "comat")
#' data(raster_w, package = "comat")
#'
#' wom = get_wecoma(raster_x, raster_w)
#' wom
#'
#' wov = get_wecove(wom)
#' wov
get_wecove = function(x, ordered = TRUE, normalization = "none"){
  rcpp_get_wecove(x, ordered, normalization)
}
