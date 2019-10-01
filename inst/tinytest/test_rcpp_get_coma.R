library(raster)
data(x, package = "comat")

r1 = comat:::rcpp_get_coma(as.matrix(x), as.matrix(4))
t1 = structure(c(4L, 1L, 3L, 1L, 2L, 2L, 3L, 2L, 6L),
               .Dim = c(3L, 3L),
               .Dimnames = list(c("1", "2", "3"), c("1", "2", "3")))

expect_equivalent(r1, t1)

r2 = comat:::rcpp_get_vec(r1, ordered = TRUE)
t2 = c(4, 1, 3, 1, 2, 2, 3, 2, 6)

expect_equivalent(r2, t2)

r3 = comat:::rcpp_get_vec(r1, ordered = FALSE)
t3 = c(2, 1, 1, 3, 2, 3)

expect_equivalent(r3, t3)

# dput(landscapemetrics::get_adjacencies(x, 4)[[1]])
# dput(landscapemetrics:::rcpp_get_coocurrence_vector(as.matrix(x), as.matrix(4)))
# dput(landscapemetrics:::rcpp_get_coocurrence_vector(as.matrix(x), as.matrix(4), ordered = FALSE))
