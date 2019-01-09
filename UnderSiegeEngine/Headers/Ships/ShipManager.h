#pragma once

#include "Objects/ScriptableObject.h"
#include "UnderSiegeEngineDllExport.h"
#include "Ships/ShipEnums.h"


namespace US
{
  class Ship;

  class UnderSiegeEngineDllExport ShipManager : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(ShipManager)

    public:
      void addShip(Ship* ship) { m_ships.push_back(ship); }
      void removeShip(Ship* ship) { m_ships.erase(std::find(m_ships.begin(), m_ships.end(), ship), m_ships.end()); }

      void getShipsOfType(ShipType shipType, std::vector<Ship*>& output);

    private:
      using Inherited = CelesteEngine::ScriptableObject;

      std::vector<Ship*> m_ships;
  };
}