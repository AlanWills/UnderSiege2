#include "UnderSiegeGame.h"
#include "RayTracing/RayTracingGame.h"

// Disables console window
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif


// The MAIN function, from here we start the application and run the game loop
int main()
{
  // Don't need to use unique_ptr as it will be deleted through 'current' unique_ptr
  US::UnderSiegeGame* game = new US::UnderSiegeGame();
  game->run();

  return 0;
}