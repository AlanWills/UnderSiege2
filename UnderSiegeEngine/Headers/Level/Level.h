#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "FileSystem/Path.h"
#include "Ships/PlayerShip.h"


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

      Ship* getPlayerShip() const { return m_playerShip.get(); }

      const Path& getScreenFilePath() const { return m_screenFilePath->getValue(); }
      const Path& getBackgroundFilePath() const { return m_backgroundFilePath->getValue(); }

    private:
      typedef ScriptableObject Inherited;

      void setBackground() const;
      void setPlayer() const; 

      static std::unique_ptr<Level> m_current;

      Handle<Screen> m_screen;
      std::unique_ptr<PlayerShip> m_playerShip;

      ReferenceField<Path>* m_screenFilePath;
      ReferenceField<Path>* m_backgroundFilePath;
      ReferenceField<glm::vec2>* m_playerSpawnPosition;

      // Scriptable object needs to be able to access constructor
      friend class ScriptableObject;

      // Bindings generator needs to be able to access constructor
      friend class Bindings::BindingsGenerator;
  };
}