#include "stdafx.h"

#include "Ships/ShipController.h"
#include "Objects/GameObject.h"


namespace US
{
  REGISTER_SCRIPT(ShipController, 10)

  //------------------------------------------------------------------------------------------------
  ShipController::ShipController() :
    m_ship(nullptr)
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
  }
}