#' Create a weighted co-occurrence matrix (wecoma)
#'
#' @param x A RasterLayer with categories
#' @param w A RasterLayer with weights
#' @param neighbourhood The number of directions in which cell adjacencies are considered as neighbours:
#' 4 (rook's case) or 8 (queen's case). The default is 4.
#' @param fun "mean", "geometric_mean", or "focal". The default is "mean".
#' @param na_action "replace", "omit", or "keep". The default is "replace".
#'
#' @return A weighted co-occurrence matrix
#' @export
#'
#' @examples
#' library(comat)
#' library(raster)
#' data(x, package = "comat")
#' data(w, package = "comat")
#' plot(x)
#' plot(w)
#'
#' wom = get_wecoma(x, w)
#' wom
#'
#' get_wecoma(x, w)
#' get_wecoma2(x, w, size = 2, shift = 2)$V3
#'
get_wecoma = function(x, w, neighbourhood = 4, fun = "mean", na_action = "replace"){
  x = raster::as.matrix(x)
  w = raster::as.matrix(w)
  directions = as.matrix(neighbourhood)

  n = rcpp_get_wecoma(x, w, directions, fun, na_action)
  structure(n, class = c(class(n), "wecoma"))
}

#' @export
get_wecoma2 = function(x, y, neighbourhood = 4, size = NULL, shift = NULL, fun = "mean", na_action = "replace"){
  x = raster::as.matrix(x)
  w = raster::as.matrix(w)
  directions = as.matrix(neighbourhood)

  if (is.null(size)){
    mat = rcpp_get_wecoma(x, w, directions, fun, na_action)
    n = tibble::tibble(id = 1, row = 1, col = 1, matrix = list(mat))
  } else {
    n = get_motifels(list(x, w),
                     directions = directions,
                     size = size,
                     shift = shift,
                     what = "wecoma",
                     fun = "mean",
                     na_action = "replace")
    n = tibble::as_tibble(n)
  }

  # n
  structure(n, class = c(class(n), "coma"))
}
