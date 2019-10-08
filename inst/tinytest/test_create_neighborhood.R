diagonal_matrix = matrix(c(1, NA, 1,
                           NA, 0, NA,
                           1, NA, 1),
                         3, 3,
                         byrow = TRUE)

r1 = comat:::create_neighborhood(diagonal_matrix)
t1 = structure(c(-1L, 1L, -1L, 1L, -1L, -1L, 1L, 1L),
               .Dim = c(4L, 2L))

expect_equivalent(r1, t1)
