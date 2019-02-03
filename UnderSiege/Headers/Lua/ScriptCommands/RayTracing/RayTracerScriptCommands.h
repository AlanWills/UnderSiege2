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
        template <typename T>
        void add(RayTracing::RayTracer& tracer, const sol::table& table)
        {
          tracer.getWorld()->addObject(new T(table));
        }
      }

      void initialize();
    }
  }
}