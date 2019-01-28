#pragma once

#include "Lua/LuaState.h"
#include "RayTracing/RayTracer.h"


namespace US
{
  namespace Lua
  {
    namespace RayTracerScriptCommands
    {
      namespace Internals
      {
        void addSphere(RayTracing::RayTracer& tracer, sol::table& table);
      }

      void initialize();
    };
  }
}