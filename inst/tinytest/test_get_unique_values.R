vector_x = c(1, 1, 1, 2, 1, 2, 2, NA)

expect_equal(comat:::get_unique_values(vector_x, na_omit = TRUE), c(1, 2))
expect_equal(comat:::get_unique_values(vector_x, na_omit = FALSE), c(NA, 1, 2))
