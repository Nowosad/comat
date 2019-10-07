#' Create a co-occurrence vector (wecove)
#'
#' Converts a co-occurrence matrix (wecoma) to
#' a co-occurrence vector (wecove)
#'
#' @param x A matrix - an output of the [get_coma()] function
#' @param ordered The type of pairs considered.
#' Either "ordered" (TRUE) or "unordered" (FALSE).
#' The default is TRUE.
#' @param normalization Should the output vector be normalized?
#' Either "none" or "pdf".
#' The "pdf" option normalizes a vector to sum to one.
#' The default is "none".
#'
#' @return A co-occurrence vector
#' @export
#'
#' @examples
#' library(comat)
#' data(raster_x, package = "comat")
#'
#' com = get_coma(raster_x)
#' com
#'
#' cov = get_cove(com)
#' cov
get_cove = function(x, ordered = TRUE, normalization = "none"){
  rcpp_get_cove(x, ordered, normalization)
}
