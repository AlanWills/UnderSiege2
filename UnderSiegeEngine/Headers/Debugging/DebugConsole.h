#pragma once

#include "Objects/Script.h"
#include "UnderSiegeEngineDllExport.h"


namespace US
{
  namespace Debugging
  {
    class UnderSiegeEngineDllExport DebugConsole : public CelesteEngine::Script
    {
      DECLARE_SCRIPT(DebugConsole)

      protected:
        void onHandleInput() override;

      private:
        using Inherited = CelesteEngine::Script;

        void reloadScreen();
        void reloadPlayer();
        void reloadEnemies();
        void reloadGUI();
    };
  }
}