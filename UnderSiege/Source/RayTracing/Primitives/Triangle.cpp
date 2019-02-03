#include "stdafx.h"

#include "RayTracing/Primitives/Triangle.h"
#include "Deserialization/MathsDeserializers.h"


namespace US
{
  namespace RayTracing
  {
    //--------------------------------------------------------------------------------------------------
    Triangle::Triangle(const sol::table& table) :
      Inherited(table),
      m_p1(),
      m_p2(),
      m_p3()
    {
      CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("p1", "0,0,0"), m_p1);
      CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("p2", "0,0,0"), m_p2);
      CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("p3", "0,0,0"), m_p3);
    }

    //--------------------------------------------------------------------------------------------------
    bool Triangle::hit(const US::RayTracing::Ray& ray, float& tMin, ShadeRec& shadeRect) const
    {
      /*s = 1 / (2 * Area)*(p0y*p2x - p0x * p2y + (p2y - p0y)*px + (p0x - p2x)*py);
      t = 1 / (2 * Area)*(p0x*p1y - p0y * p1x + (p0y - p1y)*px + (p1x - p0x)*py);
      Area = 0.5 *(-p1y * p2x + p0y * (-p1x + p2x) + p0x * (p1y - p2y) + p1x * p2y);
*/
      return false;
    }
  }
}