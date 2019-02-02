#include "stdafx.h"

#include "RayTracing/Primitives/GeometricObject.h"


namespace US
{
  namespace RayTracing
  {
    //------------------------------------------------------------------------------------------------
    GeometricObject::GeometricObject(const glm::vec3& colour) :
      m_colour(colour)
    {
    }

    //------------------------------------------------------------------------------------------------
    GeometricObject::~GeometricObject()
    {
    }
  }
}