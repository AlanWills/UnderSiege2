#include "stdafx.h"

#include "Shields/ShieldController.h"
#include "Shields/Shield.h"
#include "Objects/GameObject.h"
#include "GraphicalFX/OpacityLerper.h"
#include "Rendering/SpriteRenderer.h"


namespace US
{
  REGISTER_SCRIPT(ShieldController, 10)

  //------------------------------------------------------------------------------------------------
  ShieldController::ShieldController() :
    m_shield(nullptr),
    m_shieldStrength(1)
  {
  }

  //------------------------------------------------------------------------------------------------
  ShieldController::~ShieldController()
  {
  }

  //------------------------------------------------------------------------------------------------
  void ShieldController::onDeath()
  {
    Inherited::onDeath();

    m_shield = nullptr;
    m_shieldStrength = 1;
  }

  //------------------------------------------------------------------------------------------------
  void ShieldController::setShield(const Shield* shield)
  {
    m_shield = shield;
    if (m_shield != nullptr)
    {
      m_shieldStrength = shield->getShieldStrength();
    }
  }

  //------------------------------------------------------------------------------------------------
  void ShieldController::damage(float damage)
  {
    if (m_shieldStrength > 0)
    {
      getGameObject()->findComponent<Rendering::SpriteRenderer>()->setOpacity(1);
    }

    m_shieldStrength = std::max(0.0f, m_shieldStrength - damage);

    if (m_shieldStrength == 0)
    {
      getGameObject()->setActive(false);
      getGameObject()->setShouldRender(false);
    }
  }
}