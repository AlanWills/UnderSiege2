#include "stdafx.h"

#include "Ships/ShipManager.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Ships/ShipController.h"
#include "Ships/Ship.h"


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(ShipManager)

  //------------------------------------------------------------------------------------------------
  ShipManager::ShipManager() :
    m_ships()
  {
  }

  //------------------------------------------------------------------------------------------------
  void ShipManager::getShipsOfType(ShipType shipType, std::vector<Handle<GameObject>>& output)
  {
    std::copy_if(m_ships.begin(), m_ships.end(), std::back_inserter(output), [&](Handle<GameObject> ship) {
      return ship->findComponent<ShipController>()->getShip()->getShipType() == shipType;
    });
  }
}