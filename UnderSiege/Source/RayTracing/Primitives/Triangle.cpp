#include "stdafx.h"

#include "RayTracing/Primitives/Triangle.h"
#include "Deserialization/MathsDeserializers.h"


namespace US
{
  namespace RayTracing
  {
    //--------------------------------------------------------------------------------------------------
    const double Triangle::s_epsilon = 0.001;

    //--------------------------------------------------------------------------------------------------
    Triangle::Triangle(const sol::table& table) :
      Inherited(table),
      m_v0(),
      m_v1(),
      m_v2()
    {
      CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("v0", "0,0,0"), m_v0);
      CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("v1", "0,0,0"), m_v1);
      CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("v2", "0,0,0"), m_v2);
    }

    //--------------------------------------------------------------------------------------------------
    bool Triangle::hit(const US::RayTracing::Ray& ray, float& tMin, ShadeRec& shadeRect) const
    {
      glm::vec3 edge1, edge2, h, s, q;
      float a, f, u, v;
      edge1 = m_v1 - m_v0;
      edge2 = m_v2 - m_v0;
      h = glm::cross(ray.getDirection(), edge2);
      a = glm::dot(edge1, h);
      if (a > -s_epsilon && a < s_epsilon)
      {
        return false;    // This ray is parallel to this triangle.
      }

      f = 1.0 / a;
      s = ray.getOrigin() - m_v0;
      u = f * (glm::dot(s, h));
      if (u < 0.0 || u > 1.0)
      {
        return false;
      }

      q = glm::cross(s, edge1);
      v = f * glm::dot(ray.getDirection(), q);
      if (v < 0.0 || u + v > 1.0)
      {
        return false;
      }

      // At this stage we can compute t to find out where the intersection point is on the line.
      float t = f * glm::dot(edge2, q);
      if (t > s_epsilon) // ray intersection
      {
        if (t < tMin)
        {
          shadeRect.normal = glm::cross(edge1, edge2);
          shadeRect.local_hit_point = ray.getOrigin() + ray.getDirection() * t;
          shadeRect.color = getColour();
          tMin = t;
        }
        
        return true;
      }
      
      return false;
    }
  }
}