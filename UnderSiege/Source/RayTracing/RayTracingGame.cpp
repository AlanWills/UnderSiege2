#include "stdafx.h"

#include "RayTracing/RayTracingGame.h"
#include "Lua/LuaState.h"
#include "Lua/ScriptCommands/RayTracing/RayTracerScriptCommands.h"


namespace US
{
  namespace RayTracing
  {
    //------------------------------------------------------------------------------------------------
    void RayTracingGame::onInitialize()
    {
      Inherited::onInitialize();

      Lua::RayTracerScriptCommands::initialize();
      CelesteEngine::Lua::LuaState::scriptFile(Path(Resources::getResourcesDirectory(), "Scripts", "RayTracer.lua"));
    }
  }
}