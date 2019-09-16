#' Create a co-occurrence matrix (coma)
#'
#' @param x A RasterLayer with categories
#' @param neighbourhood The number of directions in which cell adjacencies are considered as neighbours:
#' 4 (rook's case) or 8 (queen's case). The default is 4.
#'
#' @return A co-occurrence matrix
#' @export
#'
#' @examples
#' library(comat)
#' library(raster)
#' data(x, package = "comat")
#' plot(x)
#'
#' com = get_coma(x)
#' com
#'
#' com2 = get_coma2(x, neighbourhood = 4, size = 2, shift = 2)
#' com2
#'
#' com3 = get_coma2(x, neighbourhood = 4)
#' com3
#'
#' get_coma(x)
#' get_coma2(x, neighbourhood = 4, size = 3, shift = 3)$V3
get_coma = function(x, neighbourhood = 4){
  x = raster::as.matrix(x)
  directions = as.matrix(neighbourhood)

  n = rcpp_get_coma(x, directions)
  structure(n, class = c(class(n), "coma"))
}

#' @export
get_coma2 = function(x, neighbourhood = 4, size = NULL, shift = NULL){
  x = raster::as.matrix(x)
  directions = as.matrix(neighbourhood)

  if (is.null(size)){
    mat = rcpp_get_coma(x, directions)
    n = tibble::tibble(id = 1, row = 1, col = 1, matrix = list(mat))
  } else {
    n = get_motifels(list(x), directions = directions,
                     size = size, shift = shift,
                     what = "coma")
    n = tibble::as_tibble(n)
  }

  n
  # structure(n, class = c(class(n), "coma"))
}
