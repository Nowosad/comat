library(raster)
set.seed(2019-08-23)
l1 = raster(matrix(sample(1:2, size = 100, replace = TRUE), ncol = 10))
l2 = raster(matrix(sample(c(9, 6, 3), size = 100, replace = TRUE), ncol = 10))
x = stack(l1, l2, l1)

r1 = comat:::rcpp_get_incoma(lapply(as.list(x), raster::as.matrix), matrix(4))

t1 = list(
  structure(
    c(76L, 93L, 93L, 98L),
    .Dim = c(2L, 2L),
    .Dimnames = list(c("1", "2"), c("1", "2"))
  ),
  structure(
    c(61L, 62L, 68L, 77L, 40L, 52L),
    .Dim = 2:3,
    .Dimnames = list(c("1", "2"), c("3", "6", "9"))
  ),
  structure(
    c(76L, 93L, 93L, 98L),
    .Dim = c(2L, 2L),
    .Dimnames = list(c("1", "2"), c("1", "2"))
  ),
  structure(
    c(61L, 68L, 40L, 62L, 77L, 52L),
    .Dim = 3:2,
    .Dimnames = list(c("3", "6", "9"), c("1", "2"))
  ),
  structure(
    c(40L, 57L, 26L, 57L, 50L, 38L, 26L, 38L, 28L),
    .Dim = c(3L, 3L),
    .Dimnames = list(c("3", "6", "9"), c("3", "6", "9"))
  ),
  structure(
    c(61L, 68L, 40L, 62L, 77L, 52L),
    .Dim = 3:2,
    .Dimnames = list(c("3", "6", "9"), c("1", "2"))
  ),
  structure(
    c(76L, 93L, 93L, 98L),
    .Dim = c(2L, 2L),
    .Dimnames = list(c("1", "2"), c("1", "2"))
  ),
  structure(
    c(61L, 62L, 68L, 77L, 40L, 52L),
    .Dim = 2:3,
    .Dimnames = list(c("1", "2"), c("3", "6", "9"))
  ),
  structure(
    c(76L, 93L, 93L, 98L),
    .Dim = c(2L, 2L),
    .Dimnames = list(c("1", "2"), c("1", "2"))
  )
)



expect_equivalent(r1, t1)

r2 = comat:::rcpp_get_incoma_matrix(r1)
t2 = structure(c(76, 93, 61, 68, 40, 76, 93, 93, 98, 62, 77, 52, 93,
                 98, 61, 62, 40, 57, 26, 61, 62, 68, 77, 57, 50, 38, 68, 77, 40,
                 52, 26, 38, 28, 40, 52, 76, 93, 61, 68, 40, 76, 93, 93, 98, 62,
                 77, 52, 93, 98), .Dim = c(7L, 7L),
               .Dimnames = list(c("1", "2", "3", "6", "9", "1", "2"),
                                c("1", "2", "3", "6", "9", "1", "2")))

expect_equivalent(r2, t2)
