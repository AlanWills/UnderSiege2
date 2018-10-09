#include "stdafx.h"

#include "Shields/Shield.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Serialization/MathsSerializers.h"


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Shield)

  //------------------------------------------------------------------------------------------------
  Shield::Shield() :
    m_strength(createValueField("strength", 100)),
    m_rechargePerSecond(createValueField("recharge_per_second", 1)),
    m_texture(createHandleField<Texture2D>("texture")),
    m_colour(createReferenceField("colour", glm::vec3(1)))
  {
  }
}