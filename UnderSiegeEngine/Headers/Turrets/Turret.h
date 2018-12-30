#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/ScriptableObject.h"
#include "Serialization/MathsSerializers.h"


namespace US
{
  class Bullet;
  class Ship;

  class UnderSiegeEngineDllExport Turret : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(Turret)

    public:
      float getDamage() const { return m_damage->getValue(); }
      float getFireRate() const { return m_fireRate->getValue(); }
      const Path& getTurretSprite() const { return m_turretSprite->getValue(); }
      const glm::uvec2& getTurretSpriteSheetDimensions() const { return m_turretSpriteSheetDimensions->getValue(); }
      const Bullet* getBullet() const { return m_bullet; }
      const Handle<GameObject>& getGameObject() const { return m_gameObject; }
      const Ship* getShip() const { return m_ship; }

      Handle<GameObject> create(const Handle<Screen>& screen, const Ship* ship);

    protected:
      bool doDeserialize(const tinyxml2::XMLElement* element) override;

    private:
      ValueField<float>* m_damage;
      ValueField<float>* m_fireRate;
      ReferenceField<Path>* m_turretSprite;
      ReferenceField<glm::uvec2>* m_turretSpriteSheetDimensions;
      ReferenceField<Path>* m_turretPrefab;
      ReferenceField<Path>* m_bulletAsset;
    
      Handle<GameObject> m_gameObject;
      const Ship* m_ship;
      Bullet* m_bullet;
  };
}