#' Create a weighted co-occurrence matrix (wecoma)
#'
#' @param x A matrix with categories
#' @param w A matrix with weights
#' @param neighbourhood The number of directions in which cell adjacencies are considered as neighbours:
#' 4 (rook's case) or 8 (queen's case). The default is 4.
#' @param classes A vector or a list with the values of selected classes from the `x` object.
#' It is used to calculate wecoma only for selected classes.
#' @param fun "mean", "geometric_mean", or "focal". The default is "mean".
#' @param na_action "replace", "omit", or "keep". The default is "replace".
#'
#' @return A weighted co-occurrence matrix
#' @export
#'
#' @examples
#' library(comat)
#' data(raster_x, package = "comat")
#' data(raster_w, package = "comat")
#'
#' wom = get_wecoma(raster_x, raster_w)
#' wom
#'
#' get_wecoma(raster_x, raster_w, classes = list(c(1, 3)))
get_wecoma = function(x, w, neighbourhood = 4, classes = NULL, fun = "mean", na_action = "replace"){

  if (is.null(classes)){
    classes = get_unique_values(x, TRUE)
  }
  if (inherits(classes, "integer")){
    classes = list(classes)
  }

  directions = as.matrix(neighbourhood)

  rcpp_get_wecoma_internal(x, w, directions, classes[[1]], fun, na_action)
}
