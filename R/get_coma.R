#' Create a co-occurrence matrix (coma)
#'
#' @param x A matrix with categories
#' @param neighbourhood The number of directions in which cell adjacencies are considered as neighbours:
#' 4 (rook's case) or 8 (queen's case). The default is 4.
#' @param classes A vector or a list with the values of selected classes from the `x` object.
#' It is used to calculate coma only for selected classes.
#'
#' @return A co-occurrence matrix
#' @export
#'
#' @examples
#' #library(comat)
#' data(raster_x, package = "comat")
#'
#' com = get_coma(raster_x)
#' com
#'
#' com2 = get_coma(raster_x, classes = c(1, 3))
#' com2
#'
#' data(raster_x_na, package = "comat")
#' com3 = get_coma(raster_x_na, classes = c(0:3, NA))
#' com3
get_coma = function(x, neighbourhood = 4, classes = NULL){

  if (is.null(classes)){
    classes = get_unique_values(x, TRUE)
  }
  if (inherits(classes, "integer")){
    classes = list(classes)
  }

  directions = as.matrix(neighbourhood)

  rcpp_get_coma_internal(x, directions, classes[[1]])
}
