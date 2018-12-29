#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/ScriptableObject.h"
#include "Resources/2D/Texture2D.h"


namespace CelesteEngine
{
  class Screen;
}

namespace US
{
  class Turret;
  class Shield;

  class UnderSiegeEngineDllExport Ship : public CelesteEngine::ScriptableObject
  {
    public:
      Ship();

      const Handle<Resources::Texture2D>& getTexture() const { return m_texture->getValue(); }
      float getHullStrength() const { return m_hullStrength->getValue(); }
      const std::vector<Turret*>& getTurrets() const { return m_turrets; }

      Handle<GameObject> create(const Handle<Screen>& screen) const;
      Handle<GameObject> createDeathAnimation(const Handle<Screen>& screen) const;

    protected:
      bool doDeserialize(const tinyxml2::XMLElement* element) override;

      virtual void onCreate(const Handle<GameObject>& gameObject) const = 0;

    private:
      HandleField<Resources::Texture2D>* m_texture;
      ValueField<float>* m_hullStrength;
      ReferenceField<Path>* m_shieldAsset;
      ReferenceField<Path>* m_shipPrefab;
      ReferenceField<Path>* m_deathAnimationPrefab;

	    Shield* m_shield;
      std::vector<Turret*> m_turrets;
  };
}