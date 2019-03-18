#include "stdafx.h"

#include "Ships/ShipController.h"
#include "Ships/Ship.h"
#include "Objects/GameObject.h"
#include "Shields/Shield.h"


namespace US
{
  REGISTER_SCRIPT(ShipController, 10)

  //------------------------------------------------------------------------------------------------
  ShipController::ShipController() :
    m_ship(nullptr),
    m_hullStrength(1)
  {
  }

  //------------------------------------------------------------------------------------------------
  ShipController::~ShipController()
  {
  }

  //------------------------------------------------------------------------------------------------
  void ShipController::onDeath()
  {
    Inherited::onDeath();

    m_ship = nullptr;
    m_hullStrength = 1;
  }

  //------------------------------------------------------------------------------------------------
  void ShipController::setShip(const Ship* ship)
  {
    m_ship = ship;
    if (m_ship != nullptr)
    {
      m_hullStrength = ship->getHullStrength();
    }
  }

  //------------------------------------------------------------------------------------------------
  void ShipController::damage(float damage)
  {
    if (damage > 0)
    {
      m_hullStrength = std::max(0.0f, m_hullStrength - damage);

      if (m_hullStrength <= 0)
      {
        Handle<GameObject> deathAnimation = m_ship->createDeathAnimation(getGameObject()->getScreen());
        deathAnimation->getTransform()->setWorldTranslation(getTransform()->getWorldTranslation());

        // Kill this after we have created the death animation, otherwise the owner screen will be null
        getGameObject()->die();
      }
    }
  }
}