#include "stdafx.h"

#include "Lua/ScriptCommands/RayTracing/RayTracerScriptCommands.h"


namespace US
{
  namespace Lua
  {
    namespace RayTracerScriptCommands
    {
      namespace Internals
      {
        //------------------------------------------------------------------------------------------------
        void addSphere(RayTracing::RayTracer& tracer, sol::table& table)
        {

        }
      }

      //------------------------------------------------------------------------------------------------
      void initialize()
      {
        sol::state& state = CelesteEngine::Lua::LuaState::instance();

        state.new_usertype<RayTracing::RayTracer>(
          "RayTracer",
          "allocate", sol::factories(&RayTracing::RayTracer::allocate),
          "addSphere", &Internals::addSphere);
      }
    }
  }
}