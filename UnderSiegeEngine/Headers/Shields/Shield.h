#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/ScriptableObject.h"


namespace US
{
  class Ship;

  class UnderSiegeEngineDllExport Shield : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(Shield)

    public:
  	  const Handle<Resources::Texture2D>& getTexture() const { return m_texture->getValue(); }
      float getShieldStrength() const { return m_strength->getValue(); }

      const Ship* getShip() const { return m_ship; }
      void setShip(const Ship* ship) { m_ship = ship; }

      Handle<GameObject> create(const Handle<Screen>& screen) const;

    private:
      ValueField<float>* m_strength;
      ValueField<float>* m_rechargePerSecond;
      HandleField<Resources::Texture2D>* m_texture;
      ReferenceField<glm::vec3>* m_colour;
      ReferenceField<Path>* m_shieldPrefab;

      const Ship* m_ship;
  };
}