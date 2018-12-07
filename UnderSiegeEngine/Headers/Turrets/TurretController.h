#pragma once

#include "Objects/Script.h"
#include "UnderSiegeEngineDllExport.h"


namespace CelesteEngine
{
  class Animation;
}

namespace US
{
  class Turret;

  class UnderSiegeEngineDllExport TurretController : public CelesteEngine::Script
  {
    DECLARE_SCRIPT(TurretController)

    public:
      const Turret* getTurret() const { return m_turret; }
      void setTurret(const Turret* turret) { m_turret = turret; }

    protected:
      void onSetGameObject(const Handle<GameObject>& gameObject) override;
      void onHandleInput() override;
      void onUpdate(float elapsedGameTime) override;
      void onDeath() override;

    private:
      using Inherited = CelesteEngine::Script;

      const Turret* m_turret;
      Handle<Animation> m_turretAnimation;
      float m_currentFireTimer;
  };
}