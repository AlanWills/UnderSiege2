#pragma once

#include "Objects/Script.h"
#include "UnderSiegeEngineDllExport.h"


namespace US
{
  class Bullet;

  class UnderSiegeEngineDllExport BulletController : public CelesteEngine::Script
  {
    DECLARE_SCRIPT(BulletController)

    public:
      const Bullet* getBullet() const { return m_bullet; }
      void setBullet(const Bullet* bullet);

    protected:
      void onTriggerEnter(const Handle<Physics::Collider>& collider) override;
      void onDeath() override;

    private:
      using Inherited = CelesteEngine::Script;

      const Bullet* m_bullet;

      float m_damage;
  };
}