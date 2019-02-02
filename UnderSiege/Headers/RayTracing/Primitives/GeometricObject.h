#pragma once

#include "RayTracing/Ray.h"
#include "RayTracing/ShadeRec.h"


namespace US
{
  namespace RayTracing
  {
    class GeometricObject
    {
      public:
        GeometricObject(const glm::vec3& colour);
        virtual ~GeometricObject();

        const glm::vec3& getColour() const { return m_colour; }
        void setColour(const glm::vec3& colour) { m_colour = colour; }

        virtual bool hit(const US::RayTracing::Ray& ray, float& tmin, ShadeRec& shadeRec) const = 0;

      private:
        glm::vec3 m_colour;
    };
  }
}