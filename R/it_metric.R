#' Calculates an Information Theory-based metric
#'
#' Calculates a selected Information Theory-based metric based on a provided co-occurrence matrix
#'
#' @param x A matrix - an output of the [get_coma()] function
#' @param metric One of the following: "ent" (Marginal entropy), "joinent" (Joint entropy), "condent" (Conditional entropy), "mutinf" (Mutual information), or "relmutinf" (Relative mutual information)
#' @param base The unit in which entropy is measured.
#' The default is "log2", which compute entropy in "bits".
#' "log" and "log10" can be also used.
#' @param ordered The type of pairs considered.
#' Either "ordered" (TRUE) or "unordered" (FALSE).
#' The default is TRUE.
#'
#' @return A single numeric value
#' @export
#'
#' @references
#' Nowosad J., TF Stepinski. 2019. Information theory as a consistent framework
#' for quantification and classification of landscape patterns. https://doi.org/10.1007/s10980-019-00830-x
#'
#' @examples
#' library(comat)
#' data(raster_x, package = "comat")
#'
#' com = get_coma(raster_x)
#' com
#'
#' it_metric(com, metric = "ent")
#' it_metric(com, metric = "joinent")
#' it_metric(com, metric = "condent")
#' it_metric(com, metric = "mutinf")
#' it_metric(com, metric = "relmutinf")
it_metric = function(x, metric, base = "log2", ordered = TRUE){
  if (metric == "ent"){
    result = rcpp_ent(x, base = base)
  } else if (metric == "joinent"){
    result = rcpp_joinent(x, base = base, ordered = ordered)
  } else if (metric == "condent"){
    result = rcpp_condent(x, base = base, ordered = ordered)
  } else if (metric == "mutinf"){
    result = rcpp_mutinf(x, base = base, ordered = ordered)
  } else if (metric == "relmutinf"){
    result = rcpp_relmutinf(x, base = base, ordered = ordered)
  } else{
    stop("The 'metric' argument should one of the following: 'ent', 'joinent', 'condent', 'mutinf', or 'relmutinf'", call. = FALSE)
  }
  return(result)
}
