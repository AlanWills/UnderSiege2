#include "stdafx.h"

#include "RayTracing/Primitives/Primitive.h"
#include "Deserialization/MathsDeserializers.h"


namespace US
{
  namespace RayTracing
  {
    //------------------------------------------------------------------------------------------------
    Primitive::Primitive(const glm::vec3& colour) :
      m_colour(colour)
    {
    }

    //------------------------------------------------------------------------------------------------
    Primitive::Primitive(const sol::table& table) :
      m_colour()
    {
      CelesteEngine::deserialize<glm::vec3>(table.get_or<std::string>("colour", "1"), m_colour);
    }

    //------------------------------------------------------------------------------------------------
    Primitive::~Primitive()
    {
    }
  }
}