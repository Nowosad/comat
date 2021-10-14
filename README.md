
<!-- README.md is generated from README.Rmd. Please edit that file -->

# comat

<!-- badges: start -->

[![Travis build
status](https://travis-ci.org/Nowosad/comat.svg?branch=master)](https://travis-ci.org/Nowosad/comat)
[![Codecov test
coverage](https://codecov.io/gh/Nowosad/comat/branch/master/graph/badge.svg)](https://app.codecov.io/gh/Nowosad/comat?branch=master)
[![CRAN
status](https://www.r-pkg.org/badges/version/comat)](https://CRAN.R-project.org/package=comat)
[![CRAN RStudio mirror
downloads](http://cranlogs.r-pkg.org/badges/comat)](https://cran.r-project.org/package=comat)
<!-- badges: end -->

The goal of **comat** is to create co-occurrence matrices based on
spatial data, including a weighted co-occurrence matrix (*wecoma*) and
an integrated co-occurrence matrix (*incoma*).

## Installation

You can install the released version of **comat** from
[CRAN](https://CRAN.R-project.org) with:

``` r
install.packages("comat")
```

You can install the development version from
[GitHub](https://github.com/) with:

``` r
# install.packages("remotes")
remotes::install_github("Nowosad/comat")
```

## Example

This is a basic example which shows you how to create a weighted
co-occurrence matrix (*wecoma*) based on two simple rasters (for
simplicity presented as matrices). The first one `raster_x` represents
some categories, and the second one `raster_w` represents weights.

``` r
library(comat)
library(raster)
#> Loading required package: sp
data(raster_x, package = "comat")
data(raster_w, package = "comat")
raster_x
#>      [,1] [,2] [,3]
#> [1,]    1    1    3
#> [2,]    1    3    3
#> [3,]    2    2    3
raster_w
#>      [,1] [,2] [,3]
#> [1,]    2    2    9
#> [2,]    6    4    9
#> [3,]    4    8    9
```

The `get_wecoma()` function can be next used to create a weighted
co-occurrence matrix.

``` r
get_wecoma(
  raster_x,
  raster_w,
  neighbourhood = 4
)
#>      1    2    3
#> 1 12.0  5.0 13.5
#> 2  5.0 12.0 14.5
#> 3 13.5 14.5 49.0
```

This function allows for some parametrization using additional
arguments, e.g.:

``` r
get_wecoma(
  raster_x,
  raster_w,
  neighbourhood = 4,
  fun = "focal",
  na_action = "keep"
)
#>    1  2  3
#> 1 12  6 10
#> 2  4 12 16
#> 3 17 13 49
```

## Documentation

For more examples see the package’s vignettes:

1.  [A co-occurrence matrix (coma)
    representation](https://nowosad.github.io/comat/articles/coma.html)
2.  [A weighted co-occurrence matrix (wecoma)
    representation](https://nowosad.github.io/comat/articles/wecoma.html)
3.  [An integrated co-occurrence matrix (incoma)
    representation](https://nowosad.github.io/comat/articles/incoma.html)

## Contribution

Contributions to this package are welcome. The preferred method of
contribution is through a GitHub pull request. Feel free to contact me
by creating [an issue](https://github.com/Nowosad/comat/issues).

## Citation

To cite the `comat` package in publications, please use [this
paper](https://doi.org/10.1016/j.apgeog.2020.102239):

Nowosad J, Stepinski TF (2021) Pattern-based identification and mapping
of landscape types using multi-thematic data, International Journal of
Geographical Information Science, DOI: 10.1080/13658816.2021.1893324

LaTeX/BibTeX version can be obtained with:

    library(comat)
    citation("comat")
