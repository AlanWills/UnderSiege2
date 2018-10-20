#include "UnderSiegeGame.h"

extern "C" {
# include "lua.hpp"
# include "lauxlib.h"
# include "lualib.h"
}
#include "LuaBridge/LuaBridge.h"
#include <iostream>



// Disables console window
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

using namespace luabridge;
int main() {
  lua_State* L = luaL_newstate();
  luaL_dofile(L, "C:\\Repos\\UnderSiege2\\UnderSiege\\bin\\x64\\Debug\\script.lua");
  luaL_openlibs(L);
  lua_pcall(L, 0, 0, 0);
  LuaRef s = getGlobal(L, "testString");
  LuaRef n = getGlobal(L, "number");
  std::string luaString = s.cast<std::string>();
  int answer = n.cast<int>();
  std::cout << luaString << std::endl;
  std::cout << "And here's our number:" << answer << std::endl;
}

//
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//  // Don't need to use unique_ptr as it will be deleted through 'current' unique_ptr
//  US::UnderSiegeGame* game = new US::UnderSiegeGame();
//  game->run();
//
//  return 0;
//}