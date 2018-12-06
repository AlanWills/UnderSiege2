#include "stdafx.h"

#include "Turrets/Turret.h"
#include "Registries/ScriptableObjectRegistry.h"


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Turret)

  //------------------------------------------------------------------------------------------------
  Turret::Turret() :
    m_damage(createValueField<int>("damage", 0)),
    m_fireRate(createValueField<float>("fire_rate", 1)),
    m_bullet(createReferenceField<std::string>("bullet")),
    m_firingAnimationFrames(createReferenceField<std::vector<Handle<Resources::Texture2D>>>("firing_animation_frames"))
  {
  }
}