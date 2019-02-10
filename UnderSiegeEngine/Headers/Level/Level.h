#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/ScriptableObject.h"
#include "Screens/Screen.h"


namespace US
{
  class UnderSiegeEngineDllExport Level : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(Level)

    public:
      const Path& getScreenPath() const { return m_screenPath->getValue(); }
      const Path& getTileMapPath() const { return m_tileMapPath->getValue(); }

      Handle<Screen> initialize();

    private:
      using Inherited = CelesteEngine::ScriptableObject;

      ReferenceField<Path>* m_screenPath;
      ReferenceField<Path>* m_tileMapPath;
  };
}