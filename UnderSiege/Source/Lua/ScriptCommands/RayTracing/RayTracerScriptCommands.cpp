#include "stdafx.h"

#include "Lua/ScriptCommands/RayTracing/RayTracerScriptCommands.h"
#include "RayTracing/Primitives/Sphere.h"
#include "RayTracing/Primitives/Plane.h"


namespace US
{
  namespace Lua
  {
    namespace RayTracerScriptCommands
    {
      namespace Internals
      {
        //------------------------------------------------------------------------------------------------
        void addPlane(RayTracing::RayTracer& tracer, sol::table& table)
        {
          glm::vec3 position;
          CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("position", "0"), position);

          glm::vec3 normal;
          CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("normal", "0,0,-1"), normal);

          glm::vec3 colour;
          CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("colour", "1"), colour);
          tracer.getWorld()->addObject(new RayTracing::Plane(position, normal, colour));
        }

        //------------------------------------------------------------------------------------------------
        void addSphere(RayTracing::RayTracer& tracer, sol::table& table)
        {
          glm::vec3 position;
          CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("position", "0"), position);

          float radius = table.get_or("radius", 1.0f);

          glm::vec3 colour;
          CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("colour", "1"), colour);
          tracer.getWorld()->addObject(new RayTracing::Sphere(position, radius, colour));
        }
      }

      //------------------------------------------------------------------------------------------------
      void initialize()
      {
        sol::state& state = CelesteEngine::Lua::LuaState::instance();

        state.new_usertype<RayTracing::RayTracer>(
          "RayTracer",
          "allocate", sol::factories(&RayTracing::RayTracer::allocate),
          "addPlane", &Internals::addPlane,
          "addSphere", &Internals::addSphere);
      }
    }
  }
}