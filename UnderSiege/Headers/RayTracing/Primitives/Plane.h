#pragma once

#include "Primitive.h"


namespace US
{
  namespace RayTracing
  {
    class Plane : public Primitive
    {
      public:
        Plane(const glm::vec3& colour);
        Plane(const glm::vec3& point, const glm::vec3& normal, const glm::vec3& colour);
        Plane(const sol::table& table);

        bool hit(const US::RayTracing::Ray& ray, float& tMin, ShadeRec& shadeRect) const override;

      private:
        using Inherited = Primitive;

        static const double s_epsilon;

        glm::vec3 m_centre;
        glm::vec3 m_normal;
    };
  }
}