#pragma once

#include "Lua/LuaState.h"
#include "RayTracing/RayTracer.h"
#include "Deserialization/MathsDeserializers.h"


namespace US
{
  namespace Lua
  {
    namespace RayTracerScriptCommands
    {
      namespace Internals
      {
        void addPlane(RayTracing::RayTracer& tracer, sol::table& table);
        void addSphere(RayTracing::RayTracer& tracer, sol::table& table);
      }

      void initialize();
    }
  }
}