#include "RayTracing/Primitives/Plane.h"


namespace US
{
  namespace RayTracing
  {
    //--------------------------------------------------------------------------------------------------
    const double Plane::s_epsilon = 0.001;

    //--------------------------------------------------------------------------------------------------
    Plane::Plane(const glm::vec3& colour) :
      Inherited(colour),
      m_point(),
      m_normal(0, 1, 0)
    {
    }

    //--------------------------------------------------------------------------------------------------
    Plane::Plane(const glm::vec3& point, const glm::vec3& normal, const glm::vec3& colour) :
      Inherited(colour),
      m_point(point),
      m_normal(normal)
    {
    }

    //--------------------------------------------------------------------------------------------------
    bool Plane::hit(const US::RayTracing::Ray& ray, float& tMin, ShadeRec& shadeRect) const
    {
      float t = (glm::dot(m_point - ray.getOrigin(), m_normal)) / (glm::dot(ray.getDirection(), m_normal));

      if (t > s_epsilon)
      {
        if (t < tMin)
        {
          tMin = t;
          shadeRect.normal = m_normal;
          shadeRect.local_hit_point = ray.getOrigin() + t * ray.getDirection();
          shadeRect.color = getColour();
        }

        return true;
      }
      else
      {
        return false;
      }
    }
  }
}