r1 = comat:::rcpp_get_entropy(c(5, 9), "log2")
r2 = comat:::rcpp_get_entropy(c(5, 9), "log")
r3 = comat:::rcpp_get_entropy(c(5, 9), "log10")

buys = c("no", "no", "yes", "yes", "yes", "no", "yes", "no", "yes", "yes", "yes", "yes", "yes", "no")
freqs = table(buys)/length(buys)

t1 = -sum(freqs * log2(freqs))
t2 = -sum(freqs * log(freqs))
t3 = -sum(freqs * log10(freqs))

expect_equal(r1, t1)
expect_equal(r2, t2)
expect_equal(r3, t3)
