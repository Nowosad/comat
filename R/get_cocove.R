#' Create a co-located co-occurrence vector (cocove)
#'
#' Converts a co-located co-occurrence matrix (cocoma) to
#' a co-located co-occurrence vector (cocove)
#'
#' @param x A matrix - an output of the [get_cocoma()] function
#' @param ordered The type of pairs considered.
#' Either "ordered" (TRUE) or "unordered" (FALSE).
#' The default is TRUE.
#' @param normalization Should the output vector be normalized?
#' Either "none" or "pdf".
#' The "pdf" option normalizes a vector to sum to one.
#' The default is "none".
#'
#' @return A co-located co-occurrence vector
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
#' coov = get_cocove(coom)
#' coov
get_cocove = function(x, ordered = TRUE, normalization = "none"){
  if (!ordered){
    warning("`ordered = FALSE` may return incorrect results for `cocove` when the input matrix is not a square matrix", call. = FALSE)
  }
  rcpp_get_cocove(x, ordered, normalization)
}
