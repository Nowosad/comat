get_normalized2 = function(x, normalization){
  sum_x = sum(x)
  if (sum_x == 0){
    return(rep(0, length(x)))
  } else if (normalization == "pdf"){
    return(x/sum_x)
  }
}


r1 = comat:::get_normalized(c(3, 4.5, 2, 1, 0.2), normalization = "pdf")
t1 = get_normalized2(c(3, 4.5, 2, 1, 0.2), normalization = "pdf")

expect_equivalent(r1, t1)
expect_equal(sum(r1), 1L)

r2 = comat:::get_normalized(c(0, 0, 0, 0, 0), normalization = "pdf")
expect_equal(sum(r2), 0L)

#?
# r3 = comat:::get_normalized(c(NA, 4.5, 2, 1, 0.2), normalization = "pdf")
# r3
