#pragma once

#include "GeometricObject.h"


namespace US
{
  namespace RayTracing
  {
    class Plane : public GeometricObject
    {
      public:
        Plane(const glm::vec3& colour);
        Plane(const glm::vec3& point, const glm::vec3& normal, const glm::vec3& colour);

        bool hit(const US::RayTracing::Ray& ray, float& tMin, ShadeRec& shadeRect) const override;

      private:
        using Inherited = GeometricObject;

        static const double s_epsilon;

        glm::vec3 m_point;
        glm::vec3 m_normal;
    };
  }
}