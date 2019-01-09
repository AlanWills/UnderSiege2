#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "FileSystem/Path.h"
#include "Ships/PlayerShip.h"
#include "Ships/ShipManager.h"


namespace CelesteEngine
{
  namespace Bindings
  {
    class BindingsGenerator;
  }
}

namespace US
{
  class UnderSiegeEngineDllExport Level : public ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(Level)

    public:
      static Level* current() { return m_current.get(); }
      void makeCurrent();

      ShipManager* getShipManager() const { return m_shipManager; }
      const Handle<Screen>& getScreen() const { return m_screen; }
      Ship* getPlayerShip() const { return m_playerShip.get(); }
      const Path& getScreenFilePath() const { return m_screenFilePath->getValue(); }
      const Path& getBackgroundFilePath() const { return m_backgroundFilePath->getValue(); }

      void loadScreen();
      void loadGUI();
      void loadPlayer();
      void loadEnemies();

    private:
      typedef ScriptableObject Inherited;

      static std::unique_ptr<Level> m_current;

      ShipManager* m_shipManager;
      Handle<Screen> m_screen;
      std::unique_ptr<PlayerShip> m_playerShip;

      ReferenceField<Path>* m_screenFilePath;
      ReferenceField<Path>* m_backgroundFilePath;
      ReferenceField<glm::vec2>* m_playerSpawnPosition;
  };
}