#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "UI/TurretGUIManager.h"

#include <memory>


namespace US
{
  class Level;

  namespace UI
  {
    class UnderSiegeEngineDllExport GUI
    {
      public:
        static GUI& instance();

        void setup(const std::unique_ptr<Level>& level);

      private:
        // Private to force everyone through the singleton
        GUI();

        GUI(const GUI&) = delete;
        GUI& operator=(const GUI&) = delete;

        std::unique_ptr<GUI> m_current;
        std::unique_ptr<TurretGUIManager> m_turretGUIManager;
    };
  }
}