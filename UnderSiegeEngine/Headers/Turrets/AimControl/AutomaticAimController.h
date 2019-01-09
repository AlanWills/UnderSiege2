#pragma once

#include "Turrets/AimControl/AimController.h"
#include "Ships/ShipEnums.h"


namespace US
{
  class Ship;

  class UnderSiegeEngineDllExport AutomaticAimController : public AimController
  {
    DECLARE_SCRIPT(AutomaticAimController)

    public:
      ShipType getTargetType() const { return m_targetType; }
      void setTargetType(ShipType shipType) { m_targetType = shipType; }

    protected:
      void onUpdate(float elapsedGameTime) override;

    private:
      using Inherited = AimController;

      ShipType m_targetType;
      Handle<GameObject> m_targetShip;
  };
}