#pragma once

#include "Ships/Ship.h"


namespace US
{
  class UnderSiegeEngineDllExport EnemyShip : public Ship
  {
    DECLARE_SCRIPTABLE_OBJECT(EnemyShip)

    protected:
      void onCreate(const Handle<GameObject>& gameObject) const override;

    private:
      using Inherited = Ship;
  };
}