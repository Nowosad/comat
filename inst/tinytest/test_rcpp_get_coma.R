library(raster)
data(x, package = "comat")

r1 = comat:::rcpp_get_coma(as.matrix(x), as.matrix(4))
t1 = structure(c(4L, 1L, 3L, 1L, 2L, 2L, 3L, 2L, 6L),
               .Dim = c(3L, 3L),
               .Dimnames = list(c("1", "2", "3"), c("1", "2", "3")))

expect_equal(r1, t1)

r2 = comat:::rcpp_get_cove(r1, as.matrix(4))
t2 = c(4, 1, 3, 1, 2, 2, 3, 2, 6)

expect_equal(r2, t2)
