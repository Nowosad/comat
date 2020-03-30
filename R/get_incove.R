#' Create an integrated co-occurrence vector (incove)
#'
#' Converts an integrated co-occurrence matrix (incoma) to
#' an integrated co-occurrence vector (incove)
#'
#' @param x A matrix - an output of the [get_incoma()] function
#' @param ordered The type of pairs considered.
#' Either "ordered" (TRUE) or "unordered" (FALSE).
#' The default is TRUE.
#' See details for more explanation.
#' @param repeated Should the repeated co-located co-occurrence matrices be used?
#' Either "repeated" (TRUE) or "unrepeated" (FALSE).
#' The default is TRUE.
#' See details for more explanation.
#' @param normalization Should the output vector be normalized?
#' Either "none" or "pdf".
#' The "pdf" option normalizes a vector to sum to one.
#' The default is "none".
#'
#' @return An integrated co-occurrence vector
#' @export
#'
#' @details All values are kept when `ordered = TRUE` and `repeated = TRUE`.
#' When `ordered = TRUE` and `repeated = FALSE` all values from cocoma (but only one cocoma for each pair) and all coma values are kept.
#' `ordered = FALSE` and `repeated = TRUE` keeps all values from cocoma, but divides coma values by 2.
#' `ordered = FALSE` and `repeated = FALSE` keeps all values from cocoma (but only one cocoma for each pair), and divides coma values by 2.
#'
#' @examples
#' library(comat)
#'
#' data(raster_x, package = "comat")
#' data(raster_w, package = "comat")
#' x = list(raster_x, raster_w, raster_x)
#'
#' incom = get_incoma(x)
#' incom
#'
#' incov1 = get_incove(incom)
#' incov1
#'
#' incov2 = get_incove(incom, ordered = FALSE)
#' incov2
#'
#' incov3 = get_incove(incom, ordered = FALSE, normalization = "pdf")
#' incov3
get_incove = function(x, ordered = TRUE, repeated = TRUE, normalization = "none"){
  x = rcpp_get_incoma_matrix_to_list(x)
  rcpp_get_incove(x, ordered, repeated, normalization)
}

