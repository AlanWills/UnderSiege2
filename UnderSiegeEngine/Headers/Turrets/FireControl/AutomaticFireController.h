#pragma once

#include "Turrets/FireControl/FireController.h"


namespace US
{
  class UnderSiegeEngineDllExport AutomaticFireController : public FireController
  {
    DECLARE_SCRIPT(AutomaticFireController)

    protected:
      void onHandleInput() override;

    private:
      using Inherited = FireController;
  };
}