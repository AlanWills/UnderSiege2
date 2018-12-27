#pragma once

#include "Objects/Script.h"
#include "UnderSiegeEngineDllExport.h"


namespace US
{
  class Ship;

  class UnderSiegeEngineDllExport ShipController : public CelesteEngine::Script
  {
    DECLARE_SCRIPT(ShipController)

    public:
      const Ship* getShip() const { return m_ship; }
      void setShip(const Ship* ship);

      void damage(float damage);

    protected:
      void onDeath() override;

    private:
      using Inherited = CelesteEngine::Script;

      const Ship* m_ship;
      float m_hullStrength;
  };
}