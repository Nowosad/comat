#' Create an integrated co-occurrence vector (wecove)
#'
#' Converts an integrated co-occurrence matrix (wecoma) to
#' an integrated co-occurrence vector (wecove)
#'
#' @param x A matrix - an output of the [get_incoma()] function
#' @param ordered The type of pairs considered.
#' Either "ordered" (TRUE) or "unordered" (FALSE).
#' The default is TRUE.
#' @param repeated Should the repeated co-located co-occurrence matrices be used?
#' Either "ordered" (TRUE) or "unordered" (FALSE).
#' The default is TRUE.
#' @param normalization Should the output vector be normalized?
#' Either "none" or "pdf".
#' The "pdf" option normalizes a vector to sum to one.
#' The default is "none".
#'
#' @return An integrated co-occurrence vector
#' @export
#'
#' @examples
#' library(comat)
#' library(raster)
#'
#' l1 = matrix(sample(1:2, size = 100, replace = TRUE), ncol = 10)
#' l2 = matrix(sample(c(9, 6, 3), size = 100, replace = TRUE), ncol = 10)
#' x = list(l1, l2, l1)
#'
#' incom = get_incoma(x)
#' incom
#'
#' incov1 = get_incove(incom)
#' incov1
#'
#' incov2 = get_incove(incom, ordered = FALSE)
#' incov2
get_incove = function(x, ordered = TRUE, repeated = TRUE, normalization = "none"){
  rcpp_get_incove(x, ordered, repeated, normalization)
}

