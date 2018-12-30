#pragma once

#include "Objects/ScriptableObject.h"
#include "UnderSiegeEngineDllExport.h"
#include "Ships/ShipEnums.h"


namespace US
{
  class UnderSiegeEngineDllExport ShipManager : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(ShipManager)

    public:
      void addShip(const Handle<GameObject>& ship) { m_ships.push_back(ship); }
      void removeShip(const Handle<GameObject>& ship) { m_ships.erase(std::find(m_ships.begin(), m_ships.end(), ship), m_ships.end()); }

      void getShipsOfType(ShipType shipType, std::vector<Handle<GameObject>>& output);

    private:
      using Inherited = CelesteEngine::ScriptableObject;

      std::vector<Handle<GameObject>> m_ships;
  };
}