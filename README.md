
<!-- README.md is generated from README.Rmd. Please edit that file -->

# lua51

<!-- badges: start -->

[![Lifecycle:
experimental](https://img.shields.io/badge/lifecycle-experimental-orange.svg)](https://lifecycle.r-lib.org/articles/stages.html#experimental)
[![CRAN
status](https://www.r-pkg.org/badges/version/lua51)](https://CRAN.R-project.org/package=lua51)
[![R build
status](https://github.com/royratcliffe/lua51/workflows/R-CMD-check/badge.svg)](https://github.com/royratcliffe/lua51/actions?workflow=R-CMD-check)
<!-- badges: end -->

The goal of `lua51` is to embedded Lua 5.1.5 within R.

## Installation

You can install the development version of `lua51` like so:

``` r
devtools::install_github("royratcliffe/lua51")
```

## Example

This is a basic example which shows you how to solve a common problem:

``` r
library(lua51)

L <- new(lua51::LuaState)
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
wraps this State into an object that you can instantiate using S4 class
mechanisms. The S4 layer acts as a thin shim between R’s object world
and the underlying Lua implementation.

Underneath the bonnet, C++ `lua::State` maps to `lua51::LuaState` in R.
The latter overloads `lua` by package and by class name; Lua appears
twice, somewhat redundantly the second time. In R however, common usage
first imports the package *then* accesses the package contents without
namespace qualifiers, making the second Lua in `LuaState` useful.
