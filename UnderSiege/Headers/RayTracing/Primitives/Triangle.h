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

        glm::vec3 m_v0;
        glm::vec3 m_v1;
        glm::vec3 m_v2;
    };
  }
}