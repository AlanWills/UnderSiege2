#pragma once

#include "Turrets/AimControl/AimController.h"


namespace US
{
  class UnderSiegeEngineDllExport AutomaticAimController : public AimController
  {
    DECLARE_SCRIPT(AutomaticAimController)

    protected:
      void onUpdate(float elapsedGameTime) override;

    private:
      using Inherited = AimController;
  };
}