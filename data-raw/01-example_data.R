library(raster)

x = raster(nrows = 3, ncols = 3,
           xmn = 0, xmx = 3, ymn = 0, ymx = 3,
           crs = NA,
           vals = c(1, 1, 3, 1, 3, 3, 2, 2, 3))

w = raster(nrows = 3, ncols = 3,
           xmn = 0, xmx = 3, ymn = 0, ymx = 3,
           crs = NA,
           vals = c(2, 2, 9, 6, 4, 9, 4, 8, 9))

# rcpp_get_coocurrence_matrix(as.matrix(x), matrix(4))
writeRaster(x, "data-raw/x.tif")
writeRaster(w, "data-raw/w.tif")
