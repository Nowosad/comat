library(raster)

x = raster(nrows = 3, ncols = 3,
           xmn = 0, xmx = 3, ymn = 0, ymx = 3,
           crs = NA,
           vals = c(1, 1, 3, 1, 3, 3, 2, 2, 3))

w = raster(nrows = 3, ncols = 3,
           xmn = 0, xmx = 3, ymn = 0, ymx = 3,
           crs = NA,
           vals = c(2, 2, 9, 6, 4, 9, 4, 8, 9))

x_na = raster(nrows = 3, ncols = 3,
           xmn = 0, xmx = 3, ymn = 0, ymx = 3,
           crs = NA,
           vals = c(1, 1, 3, NA, 3, NA, 2, 2, NA))

w_na = raster(nrows = 3, ncols = 3,
           xmn = 0, xmx = 3, ymn = 0, ymx = 3,
           crs = NA,
           vals = c(2, 2, NA, 6, NA, 9, 4, NA, 9))

# rcpp_get_coocurrence_matrix(as.matrix(x), matrix(4))
writeRaster(x, "data-raw/x.tif")
writeRaster(w, "data-raw/w.tif")
writeRaster(x_na, "data-raw/x_na.tif")
writeRaster(w_na, "data-raw/w_na.tif")

usethis::use_data(x)
usethis::use_data(w)
usethis::use_data(x_na)
usethis::use_data(w_na)

