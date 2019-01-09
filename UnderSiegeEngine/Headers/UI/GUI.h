#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "UI/TurretGUIs.h"

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

        void setup(const Level* level);
        void cleanup();

      private:
        // Private to force everyone through the singleton
        GUI();

        GUI(const GUI&) = delete;
        GUI& operator=(const GUI&) = delete;

        std::unique_ptr<TurretGUIs> m_turretGUIs;
    };
  }
}