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
        void addSphere(RayTracing::RayTracer& tracer, sol::table& table)
        {
          glm::vec3 position;
          CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("position", "0"), position);

          float radius = table.get_or("radius", 1.0f);

          glm::vec3 colour;
          CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("colour", "1"), colour);

          tracer.getWorld()->addObject(new Sphere(Point3D(position.x, position.y, position.z), radius, RGBColor(colour.r, colour.g, colour.b)));
        }
      }

      void initialize()
      {
        sol::state& state = CelesteEngine::Lua::LuaState::instance();

        state.new_usertype<RayTracing::RayTracer>(
          "RayTracer",
          "allocate", sol::factories(&RayTracing::RayTracer::allocate),
          "addSphere", &Internals::addSphere);
      }
    };
  }
}