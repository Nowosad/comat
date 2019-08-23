#' Create an integrated co-occurrence matrix (wecoma)
#'
#' @param x A RasterStack object containing categorical rasters
#' @param neighbourhood The number of directions in which cell adjacencies are considered as neighbours:
#' 4 (rook's case) or 8 (queen's case). The default is 4.
#'
#' @return An integrated co-occurrence matrix
#' @export
#'
#' @examples
#' library(raster)
#'
#' l1 = raster(matrix(sample(1:2, size = 100, replace = TRUE), ncol = 10))
#' l2 = raster(matrix(sample(c(9, 6, 3), size = 100, replace = TRUE), ncol = 10))
#' x = stack(l1, l2, l1)
#'
#' get_incoma(x)
#'
get_incoma = function(x, neighbourhood = 4){
  rasters = lapply(raster::as.list(x), raster::as.matrix)
  directions = as.matrix(neighbourhood)

  raster_pairs = expand.grid(seq_along(rasters), seq_along(rasters))

  comas = mapply(select_coma,
                 raster_pairs[, 2], raster_pairs[, 1],
                 MoreArgs = list(x = rasters, directions = directions),
                 SIMPLIFY = FALSE)

  mat_dims = vapply(comas[seq_along(rasters)], ncol, FUN.VALUE = 1)
  mat_len = sum(mat_dims)
  n = matrix(ncol = mat_len, nrow = 0)
  o = 1
  for (i in seq_along(rasters)){
    m = matrix(ncol = 0, nrow = nrow(comas[[o]]))
    for (j in seq_along(rasters)){
      m = cbind(m, comas[[o]])
      o = o + 1
    }
    n = rbind(n, m)
  }
  n
}

select_coma = function(id1, id2, x, directions){
  if (id1 == id2){
    rcpp_get_coma(x[[id1]], directions = directions)
  } else {
    rcpp_get_cocoma(x[[id1]], x[[id2]], directions = directions)
  }
}
