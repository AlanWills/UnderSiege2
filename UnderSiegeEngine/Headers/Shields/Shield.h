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
      const Handle<GameObject>& getGameObject() const { return m_gameObject; }
      const Ship* getShip() const { return m_ship; }

      Handle<GameObject> create(const Handle<Screen>& screen, const Ship* ship);

    private:
      ValueField<float>* m_strength;
      ValueField<float>* m_rechargePerSecond;
      HandleField<Resources::Texture2D>* m_texture;
      ReferenceField<glm::vec3>* m_colour;
      ReferenceField<Path>* m_shieldPrefab;

      Handle<GameObject> m_gameObject;
      const Ship* m_ship;
  };
}