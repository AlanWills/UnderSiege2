#include "stdafx.h"

#include "RayTracing/Primitives/Sphere.h"


namespace US
{
  namespace RayTracing
  {
    //--------------------------------------------------------------------------------------------------
    const double Sphere::s_epsilon = 0.001;

    //--------------------------------------------------------------------------------------------------
    Sphere::Sphere(const glm::vec3& colour) :
      Inherited(colour),
      m_centre(),
      m_radius(1)
    {
    }

    //--------------------------------------------------------------------------------------------------
    Sphere::Sphere(const glm::vec3& centre, double radius, const glm::vec3& colour) :
      Inherited(colour),
      m_centre(centre),
      m_radius(radius)
    {
    }

    //--------------------------------------------------------------------------------------------------
    bool Sphere::hit(const US::RayTracing::Ray& ray, float& tMin, ShadeRec& shadeRect) const
    {
      glm::vec3 temp = ray.getOrigin() - m_centre;

      float t = 0;
      double a = glm::dot(ray.getDirection(), ray.getDirection());
      double b = 2 * glm::dot(temp, ray.getDirection());
      double c = glm::dot(temp, temp) - m_radius * m_radius;
      double discriminant = b * b - 4 * a * c;

      if (discriminant < 0)
      {
        return false;
      }
      else
      {
        double e = std::sqrt(discriminant);
        double denominator = 2 * a;

        // Smaller root
        t = -(b + e) / denominator;

        if (t > s_epsilon)
        {
          if (t < tMin)
          {
            tMin = t;
            shadeRect.normal = (temp + t * ray.getDirection()) / m_radius;
            shadeRect.local_hit_point = ray.getOrigin() + t * ray.getDirection();
            shadeRect.color = getColour();
          }

          return true;
        }

        // Larger root
        t = (-b + e) / denominator;

        if (t > s_epsilon)
        {
          if (t < tMin)
          {
            tMin = t;
            shadeRect.normal = (temp + t * ray.getDirection()) / m_radius;
            shadeRect.local_hit_point = ray.getOrigin() + t * ray.getDirection();
            shadeRect.color = getColour();
          }

          return true;
        }

        return false;
      }
    }
  }
}