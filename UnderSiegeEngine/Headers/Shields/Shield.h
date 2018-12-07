#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/ScriptableObject.h"


namespace US
{
  class UnderSiegeEngineDllExport Shield : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(Shield)

    public:
      Shield();

  	  const Handle<Resources::Texture2D>& getTexture() const { return m_texture->getValue(); }

      Handle<GameObject> create(const Handle<Screen>& screen) const;

    private:
      ValueField<int>* m_strength;
      ValueField<int>* m_rechargePerSecond;
      HandleField<Resources::Texture2D>* m_texture;
      ReferenceField<glm::vec3>* m_colour;
      ReferenceField<Path>* m_shieldPrefab;
  };
}