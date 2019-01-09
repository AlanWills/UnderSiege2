#pragma once

#include "Turrets/FireControl/FireController.h"


namespace US
{
  class UnderSiegeEngineDllExport ManualFireController : public FireController
  {
    DECLARE_SCRIPT(ManualFireController)

    protected:
      void onHandleInput() override;

    private:
      using Inherited = FireController;
  };
}