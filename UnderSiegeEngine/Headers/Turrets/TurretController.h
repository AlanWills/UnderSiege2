#pragma once

#include "Objects/Script.h"
#include "UnderSiegeEngineDllExport.h"


namespace CelesteEngine
{
  class Animation;
}

namespace US
{
  class UnderSiegeEngineDllExport TurretController : public CelesteEngine::Script
  {
    DECLARE_SCRIPT(TurretController)

    protected:
      void onSetGameObject(const Handle<GameObject>& gameObject) override;
      void onHandleInput() override;
      void onUpdate(float elapsedGameTime) override;
      void onDeath() override;

    private:
      using Inherited = CelesteEngine::Script;

      Handle<Animation> m_turretAnimation;
      float m_currentFireTimer;
  };
}