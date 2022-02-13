#include <Rcpp.h>

#include "lua_State.h"

RCPP_MODULE(lua51) {
  using namespace Rcpp;
  class_<lua::State>("LuaState")
  .constructor()
  ;
}
