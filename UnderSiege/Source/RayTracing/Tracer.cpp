#include "stdafx.h"

#include "RayTracing/Tracer.h"


namespace US
{
  namespace RayTracing
  {
    // -------------------------------------------------------------------- default constructor

    Tracer::Tracer(void)
      : world_ptr(NULL)
    {}


    // -------------------------------------------------------------------- constructor

    Tracer::Tracer(World* _worldPtr)
      : world_ptr(_worldPtr)
    {}



    // -------------------------------------------------------------------- destructor

    Tracer::~Tracer(void) {
      if (world_ptr)
        world_ptr = NULL;
    }


    // -------------------------------------------------------------------- trace_ray

    glm::vec3 Tracer::trace_ray(const US::RayTracing::Ray& ray) const 
    {
      return (black);
    }


    // -------------------------------------------------------------------- trace_ray

    glm::vec3 Tracer::trace_ray(const US::RayTracing::Ray& ray, const int depth) const
    {
      return (black);
    }
  }
}