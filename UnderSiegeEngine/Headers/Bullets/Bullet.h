#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/ScriptableObject.h"


namespace US
{
  class Turret;

  class UnderSiegeEngineDllExport Bullet : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(Bullet)

    public:
      Bullet();

      float getSpeed() const { return m_speed->getValue(); }

      const Turret* getTurret() const { return m_turret; }
      void setTurret(const Turret* turret) { m_turret = turret; }

      Handle<GameObject> create(const Handle<Screen>& screen) const;
      Handle<GameObject> createExplosion(const Handle<Screen>& screen) const;

    private:
      ValueField<float>* m_speed;
      HandleField<Resources::Texture2D>* m_texture;
      ReferenceField<Path>* m_bulletPrefab;
      ReferenceField<Path>* m_explosionPrefab;

      const Turret* m_turret;
  };
}