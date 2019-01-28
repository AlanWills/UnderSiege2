#include "stdafx.h"

#include "RayTracing/RayTracingGame.h"
#include "Lua/LuaState.h"


namespace US
{
  namespace RayTracing
  {
    //------------------------------------------------------------------------------------------------
    void RayTracingGame::onInitialize()
    {
      Inherited::onInitialize();

      Lua::LuaState::script(Path(Resources::getResourcesDirectory(), "Scripts", "RayTracer.lua"));
    }
  }
}