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

      public:
        void reloadScreen();
        void reloadPlayer();
        void reloadEnemies();
        void reloadGUI();

      protected:
        void onSetGameObject(const Handle<GameObject>& gameObject) override;

      private:
        using Inherited = CelesteEngine::Script;
    };
  }
}