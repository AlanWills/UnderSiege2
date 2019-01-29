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
    Ray::Ray(const Point3D& origin, const Vector3D& direction) :
      m_origin(origin),
      m_direction(direction)
    {
    }
  }
}