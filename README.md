
<!-- README.md is generated from README.Rmd. Please edit that file -->

# lua51

<!-- badges: start -->

[![Lifecycle:
experimental](https://img.shields.io/badge/lifecycle-experimental-orange.svg)](https://lifecycle.r-lib.org/articles/stages.html#experimental)
[![CRAN
status](https://www.r-pkg.org/badges/version/lua51)](https://CRAN.R-project.org/package=lua51)
<!-- badges: end -->

The goal of lua51 is to …

## Installation

You can install the development version of lua51 like so:

``` r
# FILL THIS IN! HOW CAN PEOPLE INSTALL YOUR DEV PACKAGE?
```

## Example

This is a basic example which shows you how to solve a common problem:

``` r
library(lua51)
## basic example code
```

## Rcpp packaging

See [Rcpp](http://www.rcpp.org/) for full details. This section simply
sets out some abbreviated notes. The package applies `use_rcpp` from
`usethis` in order to set up a C++ package.

``` r
usethis::create_tidy_package("lua51")
usethis::use_package_doc()
usethis::use_rcpp()
```

The package comprises a single `Rcpp` module.

``` cpp
RCPP_MODULE(lua51) {
  using namespace Rcpp;
}
```

But why C++ integration when Lua is pure C? The decision is one of
style. All of the low-level Lua interface functions interact with a Lua
‘State’ encapsulating a single mutable Lua state machine. The design
wraps this State into an object that you can instantiate using S6 class
mechanisms. The S6 layer acts as a thin shim between R’s object world
and the underlying Lua implementation.
