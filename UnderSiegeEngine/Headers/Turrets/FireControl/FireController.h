#pragma once

#include "Objects/Script.h"
#include "UnderSiegeEngineDllExport.h"


namespace CelesteEngine
{
  namespace Animation
  {
    class Animator;
  }
}

namespace US
{
  class Turret;

  class UnderSiegeEngineDllExport FireController : public CelesteEngine::Script
  {
    public:
      FireController();

      const Turret* getTurret() const { return m_turret; }
      void setTurret(const Turret* turret) { m_turret = turret; }

      void tryFire();

    protected:
      void onSetGameObject(const Handle<GameObject>& gameObject) override;
      void onUpdate(float elapsedGameTime) override;
      void onDeath() override;

      void setIsFiring(bool isFiring) { m_isFiring = isFiring; }

    private:
      using Inherited = CelesteEngine::Script;

      const Turret* m_turret;
      Handle<Animation::Animator> m_turretAnimation;
      float m_currentFireTimer;
      bool m_isFiring;
  };
}