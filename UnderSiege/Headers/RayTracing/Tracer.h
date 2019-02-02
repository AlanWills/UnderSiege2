#pragma once

#include "Constants.h"
#include "Ray.h"


namespace US
{
  namespace RayTracing
  {
    class World;

    class Tracer 
    {
      public:
        Tracer();
        Tracer(World* _world_ptr);

        virtual ~Tracer();

        virtual glm::vec3 trace_ray(const US::RayTracing::Ray& ray) const;
        virtual glm::vec3 trace_ray(const US::RayTracing::Ray& ray, const int depth) const;

      protected:
        World* world_ptr;
    };
  }
}