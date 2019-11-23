#' Create an integrated co-occurrence matrix (incoma)
#'
#' @param x A list object containing categorical matrices with categories
#' @param neighbourhood The number of directions in which cell adjacencies are considered as neighbours:
#' 4 (rook's case) or 8 (queen's case). The default is 4.
#' @param classes A list of the same length as `x` with the values of selected classes from all of the objects in `x`.
#' It is used to calculate incoma only for selected classes.
#'
#' @return An integrated co-occurrence matrix
#' @export
#'
#' @examples
#' data(raster_x, package = "comat")
#' data(raster_w, package = "comat")
#' x = list(raster_x, raster_w, raster_x)
#'
#' get_incoma(x)
#'
#' get_incoma(x, classes = list(1:2, 2:4, 1))
get_incoma = function(x, neighbourhood = 4, classes = NULL){

  if (is.null(classes)){
    classes = lapply(x, get_unique_values, TRUE)
  }

  directions = as.matrix(neighbourhood)

  n = rcpp_get_incoma_list(x, directions, classes)
  n = rcpp_get_incoma_matrix(n)
  n
}


