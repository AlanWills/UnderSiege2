#include "stdafx.h"

#include "Turrets/Turret.h"


namespace US
{
  //------------------------------------------------------------------------------------------------
  Turret::Turret() :
    m_damage(createValueField<int>("damage", 0)),
    m_fireRate(createValueField<int>("fire_rate", 1)),
    m_idleTexture(createHandleField<Texture2D>("idle_texture")),
    m_firingAnimationFrames(createReferenceField<std::vector<Texture2D>>("firing_animation_frames"))
  {
  }
}