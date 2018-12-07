#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/ScriptableObject.h"


namespace US
{
  class Bullet;

  class UnderSiegeEngineDllExport Turret : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(Turret)

    public:
      Turret();

      float getFireRate() const { return m_fireRate->getValue(); }
      const Bullet* getBullet() const { return m_bullet; }

      Handle<GameObject> create(const Handle<Screen>& screen) const;

    protected:
      bool doDeserialize(const tinyxml2::XMLElement* element) override;

    private:
      ValueField<int>* m_damage;
      ValueField<float>* m_fireRate;
      ReferenceField<Path>* m_bulletAsset;
      ReferenceField<Path>* m_turretPrefab;
    
      std::vector<Handle<Resources::Texture2D>> m_firingAnimationFrames;
      Bullet* m_bullet;
  };
}