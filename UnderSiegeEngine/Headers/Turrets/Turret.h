#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/ScriptableObject.h"


namespace US
{
  class Bullet;
  class Ship;

  class UnderSiegeEngineDllExport Turret : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(Turret)

    public:
      Turret();

      float getDamage() const { return m_damage->getValue(); }
      float getFireRate() const { return m_fireRate->getValue(); }
      const Path& getTurretSprite() const { return m_turretSprite->getValue(); }
      const glm::vec2& getTurretSpriteSheetDimensions() const { return m_turretSpriteSheetDimensions->getValue(); }
      const Bullet* getBullet() const { return m_bullet; }

      const Ship* getShip() const { return m_ship; }
      void setShip(const Ship* ship) { m_ship = ship; }

      Handle<GameObject> create(const Handle<Screen>& screen) const;

    protected:
      bool doDeserialize(const tinyxml2::XMLElement* element) override;

    private:
      ValueField<float>* m_damage;
      ValueField<float>* m_fireRate;
      ReferenceField<Path>* m_turretSprite;
      ReferenceField<glm::uvec2>* m_turretSpriteSheetDimensions;
      ReferenceField<Path>* m_turretPrefab;
      ReferenceField<Path>* m_bulletAsset;
    
      const Ship* m_ship;
      Bullet* m_bullet;
  };
}