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

      float getFireRate() const { return m_fireRate->getValue(); }
      const Bullet* getBullet() const { return m_bullet; }

      const Ship* getShip() const { return m_ship; }
      void setShip(const Ship* ship) { m_ship = ship; }

      Handle<GameObject> create(const Handle<Screen>& screen) const;

    protected:
      bool doDeserialize(const tinyxml2::XMLElement* element) override;

    private:
      ValueField<int>* m_damage;
      ValueField<float>* m_fireRate;
      ReferenceField<Path>* m_bulletAsset;
      ReferenceField<Path>* m_turretPrefab;
    
      const Ship* m_ship;
      Bullet* m_bullet;
  };
}