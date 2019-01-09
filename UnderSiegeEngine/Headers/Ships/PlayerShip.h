#pragma once

#include "Ships/Ship.h"


namespace US
{
  class UnderSiegeEngineDllExport PlayerShip : public Ship
  {
    DECLARE_SCRIPTABLE_OBJECT(PlayerShip)

    protected:
      void onCreate(const Handle<GameObject>& gameObject) const override;

    private:
      using Inherited = Ship;
  };
}