#pragma once

#include "Primitive.h"


namespace US
{
  namespace RayTracing
  {
    class Triangle : public Primitive
    {
      public:
        Triangle(const sol::table& table);

        bool hit(const US::RayTracing::Ray& ray, float& tMin, ShadeRec& shadeRect) const override;

      private:
        using Inherited = Primitive;

        static const double s_epsilon;

        glm::vec3 m_p1;
        glm::vec3 m_p2;
        glm::vec3 m_p3;
    };
  }
}