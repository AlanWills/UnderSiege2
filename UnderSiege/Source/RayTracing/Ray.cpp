#include "RayTracing/Ray.h"


namespace US
{
  namespace RayTracing
  {
    //--------------------------------------------------------------------------------------------------
    Ray::Ray() :
      m_origin(),
      m_direction()
    {
    }

    //--------------------------------------------------------------------------------------------------
    Ray::Ray(const glm::vec3& origin, const glm::vec3& direction) :
      m_origin(origin),
      m_direction(direction)
    {
    }
  }
}