#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/Script.h"


namespace US
{
  namespace Input
  {
    class UnderSiegeEngineDllExport LookAtCursor : public CelesteEngine::Script
    {
      DECLARE_SCRIPT(LookAtCursor)

      protected:
        void onUpdate(float elapsedGameTime) override;

      private:
        using Inherited = CelesteEngine::Script;
    };
  }
}