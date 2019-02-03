#include "stdafx.h"

#include "Lua/ScriptCommands/RayTracing/RayTracerScriptCommands.h"
#include "RayTracing/Primitives/Sphere.h"
#include "RayTracing/Primitives/Plane.h"
#include "RayTracing/Primitives/Triangle.h"


namespace US
{
  namespace Lua
  {
    namespace RayTracerScriptCommands
    {
      //------------------------------------------------------------------------------------------------
      void initialize()
      {
        sol::state& state = CelesteEngine::Lua::LuaState::instance();

        state.new_usertype<RayTracing::RayTracer>(
          "RayTracer",
          "allocate", sol::factories(&RayTracing::RayTracer::allocate),
          "addPlane", &Internals::add<RayTracing::Plane>,
          "addSphere", &Internals::add<RayTracing::Sphere>,
          "addTriangle", &Internals::add<RayTracing::Triangle>);
      }
    }
  }
}