#include "stdafx.h"

#include "RayTracing/Primitives/Plane.h"
#include "Deserialization/MathsDeserializers.h"


namespace US
{
  namespace RayTracing
  {
    //--------------------------------------------------------------------------------------------------
    const double Plane::s_epsilon = 0.001;

    //--------------------------------------------------------------------------------------------------
    Plane::Plane(const glm::vec3& colour) :
      Inherited(colour),
      m_centre(),
      m_normal(0, 1, 0)
    {
    }

    //--------------------------------------------------------------------------------------------------
    Plane::Plane(const glm::vec3& centre, const glm::vec3& normal, const glm::vec3& colour) :
      Inherited(colour),
      m_centre(centre),
      m_normal(normal)
    {
    }

    //--------------------------------------------------------------------------------------------------
    Plane::Plane(const sol::table& table) :
      Inherited(table),
      m_centre(),
      m_normal()
    {
      CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("centre", "0,0,0"), m_centre);
      CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("normal", "0,0,-1"), m_normal);
    }

    //--------------------------------------------------------------------------------------------------
    bool Plane::hit(const US::RayTracing::Ray& ray, float& tMin, ShadeRec& shadeRect) const
    {
      float t = (glm::dot(m_centre - ray.getOrigin(), m_normal)) / (glm::dot(ray.getDirection(), m_normal));

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