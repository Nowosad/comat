library(raster)
data(x, package = "comat")
data(w, package = "comat")
data(x_na, package = "comat")
data(w_na, package = "comat")

x = as.matrix(x)
w = as.matrix(w)
x_na = as.matrix(x_na)
w_na = as.matrix(w_na)

r1 = comat:::rcpp_get_wecoma(x, w, fun = "mean", na_action = "replace", directions = matrix(4))
r2 = comat:::rcpp_get_wecoma(x, w, fun = "geometric_mean", na_action = "replace", directions = matrix(4))
r3 = comat:::rcpp_get_wecoma(x, w, fun = "focal", na_action = "replace", directions = matrix(4))
r4 = comat:::rcpp_get_wecoma(x, w_na, fun = "mean", na_action = "omit", directions = matrix(4))
r5 = comat:::rcpp_get_wecoma(x, w_na, fun = "mean", na_action = "replace", directions = matrix(4))
r6 = comat:::rcpp_get_wecoma(x_na, w_na, fun = "mean", na_action = "omit", directions = matrix(4))
r7 = comat:::rcpp_get_wecoma(x_na, w_na, fun = "mean", na_action = "keep", directions = matrix(4))

t1 = structure(c(12, 5, 13.5, 5, 12, 14.5, 13.5, 14.5, 49),
               .Dim = c(3L, 3L),
               .Dimnames = list(c("1", "2", "3"), c("1", "2", "3")))
t2 = structure(c(10.9282032302755, 4.89897948556636, 11.9700472974318,
                 4.89897948556636, 11.3137084989848, 14.142135623731, 11.9700472974318,
                 14.142135623731, 48), .Dim = c(3L, 3L),
               .Dimnames = list(c("1", "2", "3"), c("1", "2", "3")))
t3 = structure(c(12, 4, 17, 6, 12, 13, 10, 16, 49),
               .Dim = c(3L, 3L),
               .Dimnames = list(c("1", "2", "3"), c("1", "2", "3")))
t4 = structure(c(12, 5, 0, 5, 0, 0, 0, 0, 18), .Dim = c(3L, 3L),
               .Dimnames = list(c("1", "2", "3"), c("1", "2", "3")))
t5 = structure(c(12, 5, 5, 5, 4, 4.5, 5, 4.5, 36), .Dim = c(3L, 3L),
               .Dimnames = list(c("1", "2", "3"), c("1", "2", "3")))
t6 = structure(c(4, 0, 0, 0, 0, 0, 0, 0, 0), .Dim = c(3L, 3L),
               .Dimnames = list(c("1", "2", "3"), c("1", "2", "3")))
t7 = structure(c(4, 0, NA, 0, NA, NA, NA, NA, 0), .Dim = c(3L, 3L),
               .Dimnames = list(c("1", "2", "3"), c("1", "2", "3")))

expect_equivalent(r1, t1)
expect_equivalent(r2, t2)
expect_equivalent(r3, t3)
expect_equivalent(r4, t4)
expect_equivalent(r5, t5)
expect_equivalent(r6, t6)
expect_equivalent(r7, t7)

expect_error(comat:::rcpp_get_wecoma(x_na, w_na, fun = "median"))

r8 = comat:::rcpp_get_wecove(r1, type = "ordered", normalization = "none")
t8 = c(12, 5, 13.5, 5, 12, 14.5, 13.5, 14.5, 49)
expect_equivalent(r8, t8)

r9 = comat:::rcpp_get_vec(r1, ordered = FALSE, normalization = "none")
t9 = c(6, 5, 6, 13.5, 14.5, 24.5)
expect_equivalent(r9, t9)
