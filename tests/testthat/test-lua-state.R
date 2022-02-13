test_that("new(LuaState) works", {
  L <- new(lua51::LuaState)
  expect_equal(class(L), structure("Rcpp_LuaState", package = "lua51"))
})
