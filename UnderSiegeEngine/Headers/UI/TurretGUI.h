#pragma once

#include "Objects/ScriptableObject.h"
#include "UnderSiegeEngineDllExport.h"


namespace CelesteEngine
{
  class Screen;
}

namespace US
{
  class Turret;

  namespace UI
  {
    class UnderSiegeEngineDllExport TurretGUI : public CelesteEngine::ScriptableObject
    {
      DECLARE_SCRIPTABLE_OBJECT(TurretGUI)

      public:
        const Handle<GameObject>& getGameObject() const { return m_gameObject; }

        void setup(const Handle<GameObject>& gameObject, const Turret* turret);

      private:
        using Inherited = CelesteEngine::ScriptableObject;

        Handle<GameObject> m_gameObject;
    };
  }
}