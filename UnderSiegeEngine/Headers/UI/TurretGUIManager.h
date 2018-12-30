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
    class UnderSiegeEngineDllExport TurretGUIManager : public CelesteEngine::ScriptableObject
    {
      DECLARE_SCRIPTABLE_OBJECT(TurretGUIManager)

      public:
        const Handle<GameObject>& getGameObject() const { return m_gameObject; }

        void setup(const Handle<GameObject>& gameObject, const std::vector<Turret*>& turrets);

      private:
        using Inherited = CelesteEngine::ScriptableObject;

        Handle<GameObject> m_gameObject;
    };
  }
}