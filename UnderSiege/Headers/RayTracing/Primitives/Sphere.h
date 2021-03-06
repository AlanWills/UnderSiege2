#pragma once

#include "Primitive.h"


namespace US
{
  namespace RayTracing
  {
    class Sphere : public Primitive
    {
      public:
        Sphere(const glm::vec3& colour);
        Sphere(const glm::vec3& centre, double radius, const glm::vec3& colour);
        Sphere(const sol::table& table);

        const glm::vec3& getCentre() const { return m_centre; }
        void setCentre(const glm::vec3& centre) { m_centre = centre; }

        double getRadius() const { return m_radius; }
        void setRadius(double radius) { m_radius = radius; }

        bool hit(const US::RayTracing::Ray& ray, float& tMin, ShadeRec& shadeRect) const override;

      private:

        using Inherited = Primitive;

        static const double s_epsilon;

        glm::vec3 m_centre;
        float m_radius;
    };
  }
}