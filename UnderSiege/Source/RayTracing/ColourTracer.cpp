#include "stdafx.h"

#include "RayTracing/ColourTracer.h"
#include "RayTracing/World.h"
#include "RayTracing/ShadeRec.h"


namespace US
{
  namespace RayTracing
  {
    // --------------------------------------------------------------------
    ColourTracer::ColourTracer(World* _worldPtr) :
      Tracer(_worldPtr)
    {
    }

    // --------------------------------------------------------------------
    ColourTracer::~ColourTracer()
    {
    }

    // --------------------------------------------------------------------
    glm::vec3 ColourTracer::trace_ray(const US::RayTracing::Ray& ray) const
    {
      ShadeRec	sr(*world_ptr); 	// not used
      float t = std::numeric_limits<float>::max();  				// not used

      for (const auto& object : *world_ptr)
      {
        object->hit(ray, t, sr);
      }

      return sr.color;
    }
  }
}