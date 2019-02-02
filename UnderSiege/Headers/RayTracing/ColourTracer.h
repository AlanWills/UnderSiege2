#pragma once

#include "Tracer.h"


namespace US
{
  namespace RayTracing
  {
    class ColourTracer : public Tracer
    {
      public:
        ColourTracer(World* _worldPtr);
        virtual	~ColourTracer(void);

        virtual glm::vec3 trace_ray(const US::RayTracing::Ray& ray) const;
    };
  }
}