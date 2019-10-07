#' Create a weighted co-occurrence vector (wecove)
#'
#' Converts a weighted co-occurrence matrix (wecoma) to
#' a weighted co-occurrence vector (wecove)
#'
#' @param x A matrix - an output of the [get_wecoma()] function
#' @param type The type of pairs considered.
#' Either "ordered" or "unordered".
#' The default is "ordered".
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
#' data(x, package = "comat")
#' data(w, package = "comat")
#'
#' wom = get_wecoma(as.matrix(x), as.matrix(w))
#' wom
#'
#' wov = get_wecove(wom)
#' wov
get_wecove = function(x, type = "ordered", normalization = "none"){
  rcpp_get_wecove(x, type, normalization)
}
