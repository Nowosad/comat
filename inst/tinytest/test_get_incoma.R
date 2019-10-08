set.seed(2019-08-23)
l1 = matrix(sample(1:2, size = 100, replace = TRUE), ncol = 10)
l2 = matrix(sample(c(9, 6, 3), size = 100, replace = TRUE), ncol = 10)

r1 = get_incoma(list(l1, l2, l1), neighbourhood = 4)

t1 = structure(c(76L, 93L, 61L, 68L, 40L, 76L, 93L, 93L, 98L, 62L,
                 77L, 52L, 93L, 98L, 61L, 62L, 40L, 57L, 26L, 61L, 62L, 68L, 77L,
                 57L, 50L, 38L, 68L, 77L, 40L, 52L, 26L, 38L, 28L, 40L, 52L, 76L,
                 93L, 61L, 68L, 40L, 76L, 93L, 93L, 98L, 62L, 77L, 52L, 93L, 98L),
               .Dim = c(7L, 7L),
               .Dimnames = list(c("1", "2", "3", "6", "9", "1", "2"),
                                c("1", "2", "3", "6", "9", "1", "2")),
               no_unique = c(2, 3, 2))

expect_equivalent(r1, t1)

r2 = get_incove(r1, ordered = TRUE, repeated = TRUE, normalization = "none")
r3 = get_incove(r1, ordered = TRUE, repeated = FALSE, normalization = "none")
r4 = get_incove(r1, ordered = FALSE, repeated = TRUE, normalization = "none")
r5 = get_incove(r1, ordered = FALSE, repeated = FALSE, normalization = "none")

t2 = c(76, 93, 93, 98, 61, 62, 68, 77, 40, 52, 76, 93, 93, 98, 61, 68, 40, 62,
       77, 52, 40, 57, 26, 57, 50, 38, 26, 38, 28, 61, 68, 40, 62, 77, 52, 76,
       93, 93, 98, 61, 62, 68, 77, 40, 52, 76, 93, 93, 98)
t3 = c(76, 93, 93, 98, 61, 62, 68, 77, 40, 52, 76, 93, 93, 98, 61,
       68, 40, 62, 77, 52, 61, 68, 40, 62, 77, 52, 76, 93, 93, 98)
t4 = c(38, 93, 49, 61, 62, 68, 77, 40, 52, 76, 93, 93, 98, 61, 68,
       40, 62, 77, 52, 20, 57, 25, 26, 38, 14, 61, 68, 40, 62, 77,
       52, 76, 93, 93, 98, 61, 62, 68, 77, 40, 52, 38, 93, 49)
t5 = c(38, 93, 49, 61, 62, 68, 77, 40, 52, 76, 93, 93, 98, 61, 68,
       40, 62, 77, 52, 61, 68, 40, 62, 77, 52, 38, 93, 49)

expect_equivalent(r2, t2)
expect_equivalent(r3, t3)
expect_equivalent(r4, t4)
expect_equivalent(r5, t5)
