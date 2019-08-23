library(raster)
set.seed(2019-08-23)
l1 = raster(matrix(sample(1:2, size = 100, replace = TRUE), ncol = 10))
l2 = raster(matrix(sample(c(9, 6, 3), size = 100, replace = TRUE), ncol = 10))
x = stack(l1, l2, l1)

r1 = get_incoma(x)

t1 = structure(c(76, 93, 61, 68, 40, 76, 93, 93, 98, 62, 77, 52, 93,
                 98, 61, 62, 40, 57, 26, 61, 62, 68, 77, 57, 50, 38, 68, 77, 40,
                 52, 26, 38, 28, 40, 52, 76, 93, 61, 68, 40, 76, 93, 93, 98, 62,
                 77, 52, 93, 98), .Dim = c(7L, 7L),
               .Dimnames = list(c("1", "2", "3", "6", "9", "1", "2"),
                                c("1", "2", "3", "6", "9", "1", "2")))

expect_equal(r1, t1)

