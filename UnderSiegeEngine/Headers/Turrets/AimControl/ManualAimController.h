#pragma once

#include "Turrets/AimControl/AimController.h"


namespace US
{
  class UnderSiegeEngineDllExport ManualAimController : public AimController
  {
    DECLARE_SCRIPT(ManualAimController)

    protected:
      void onUpdate(float elapsedGameTime) override;

    private:
      using Inherited = AimController;
  };
}