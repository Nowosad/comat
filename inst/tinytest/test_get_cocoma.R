data(raster_x, package = "comat")
data(raster_w, package = "comat")

r1 = get_cocoma(raster_x, raster_w, neighbourhood = 4)

t1 = structure(c(3L, 0L, 2L, 3L, 2L, 1L, 1L, 1L, 1L, 0L, 1L, 2L, 1L, 1L, 5L),
               .Dim = c(3L, 5L),
               .Dimnames = list(c("1", "2", "3"), c("2", "4", "6", "8", "9")))

expect_equivalent(r1, t1)

r2 = get_cocove(r1, ordered = TRUE, normalization = "none")
t2 = matrix(c(3, 0, 2, 3, 2, 1, 1, 1, 1, 0, 1, 2, 1, 1, 5), nrow = 1)

expect_equivalent(r2, t2)

data(raster_x_na, package = "comat")
data(raster_w_na, package = "comat")

r3 = get_cocoma(raster_x_na, raster_w_na, neighbourhood = 4)

t3 = structure(c(2L, 0L, 2L, 0L, 1L, 0L, 1L, 1L, 1L, 0L, 1L, 2L),
               .Dim = 3:4,
               .Dimnames = list(c("1", "2", "3"), c("2", "4", "6", "9")))

expect_equivalent(r3, t3)
