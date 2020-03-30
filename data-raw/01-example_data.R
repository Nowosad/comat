library(raster)

raster_x = raster(nrows = 3, ncols = 3,
           xmn = 0, xmx = 3, ymn = 0, ymx = 3,
           crs = NA,
           vals = c(1, 1, 3, 1, 3, 3, 2, 2, 3))

raster_y = raster(nrows = 3, ncols = 3,
           xmn = 0, xmx = 3, ymn = 0, ymx = 3,
           crs = NA,
           vals = c(5, 5, 5, 6, 6, 5, 5, 5, 6))

raster_w = raster(nrows = 3, ncols = 3,
           xmn = 0, xmx = 3, ymn = 0, ymx = 3,
           crs = NA,
           vals = c(2, 2, 9, 6, 4, 9, 4, 8, 9))

raster_x_na = raster(nrows = 3, ncols = 3,
           xmn = 0, xmx = 3, ymn = 0, ymx = 3,
           crs = NA,
           vals = c(1, 1, 3, NA, 3, NA, 2, 2, NA))

raster_w_na = raster(nrows = 3, ncols = 3,
           xmn = 0, xmx = 3, ymn = 0, ymx = 3,
           crs = NA,
           vals = c(2, 2, NA, 6, NA, 9, 4, NA, 9))

set.seed(2019-08-23)
l1 = matrix(sample(1:2, size = 100, replace = TRUE), ncol = 10)
l2 = matrix(sample(c(9, 6, 3), size = 100, replace = TRUE), ncol = 10)
ll = list(l1, l2, l1)
dir.create("inst/testdata")
saveRDS(ll, "inst/testdata/ll.rds", version = 2)

# rcpp_get_coocurrence_matrix(as.matrix(x), matrix(4))
writeRaster(raster_x, "data-raw/x.tif")
writeRaster(raster_w, "data-raw/w.tif")
writeRaster(raster_x_na, "data-raw/x_na.tif")
writeRaster(raster_w_na, "data-raw/w_na.tif")

raster_x = as.matrix(raster_x)
raster_y = as.matrix(raster_y)
raster_w = as.matrix(raster_w)
raster_x_na = as.matrix(raster_x_na)
raster_w_na = as.matrix(raster_w_na)

usethis::use_data(raster_x, overwrite = TRUE)
usethis::use_data(raster_y, overwrite = TRUE)
usethis::use_data(raster_w, overwrite = TRUE)
usethis::use_data(raster_x_na, overwrite = TRUE)
usethis::use_data(raster_w_na, overwrite = TRUE)

