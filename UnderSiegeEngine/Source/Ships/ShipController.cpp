#include "stdafx.h"

#include "Ships/ShipController.h"
#include "Objects/GameObject.h"
#include "Ships/Ship.h"


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
    m_hullStrength -= damage;
    if (m_hullStrength <= 0)
    {
      getGameObject()->die();
    }
  }
}