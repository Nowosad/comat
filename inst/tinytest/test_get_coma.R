data(raster_x, package = "comat")

r1 = get_coma(raster_x, 4)
t1 = structure(c(4L, 1L, 3L, 1L, 2L, 2L, 3L, 2L, 6L),
               .Dim = c(3L, 3L),
               .Dimnames = list(c("1", "2", "3"), c("1", "2", "3")))

expect_equivalent(r1, t1)

r2 = get_cove(r1, ordered = TRUE, normalization = "none")
t2 = matrix(c(4, 1, 3, 1, 2, 2, 3, 2, 6), nrow = 1)

expect_equivalent(r2, t2)

r3 = get_cove(r1, ordered = FALSE, normalization = "none")
t3 = matrix(c(2, 1, 1, 3, 2, 3), nrow = 1)

expect_equivalent(r3, t3)

data(raster_x_na, package = "comat")

r4 = get_coma(raster_x_na, 4)
t4 = structure(c(2L, 0L, 2L, 0L, 2L, 1L, 2L, 1L, 0L),
               .Dim = c(3L, 3L),
               .Dimnames = list(c("1", "2", "3"), c("1", "2", "3")))

expect_equivalent(r4, t4)

r5 = get_coma(raster_x, 8)
t5 = structure(c(6L, 2L, 5L, 2L, 2L, 4L, 5L, 4L, 10L),
               .Dim = c(3L, 3L),
               .Dimnames = list(c("1", "2", "3"), c("1", "2", "3")))

expect_equivalent(r5, t5)

# dput(landscapemetrics::get_adjacencies(x, 4)[[1]])
# dput(landscapemetrics:::rcpp_get_coocurrence_vector(as.matrix(x), as.matrix(4)))
# dput(landscapemetrics:::rcpp_get_coocurrence_vector(as.matrix(x), as.matrix(4), ordered = FALSE))
