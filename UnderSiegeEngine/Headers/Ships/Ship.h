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
    DECLARE_SCRIPTABLE_OBJECT(Ship)

    public:
      Ship();

      const Handle<Resources::Texture2D>& getTexture() const { return m_texture->getValue(); }
      float getHullStrength() const { return m_hullStrength->getValue(); }
      const std::vector<Turret*>& getTurrets() const { return m_turrets; }

      Handle<GameObject> create(const Handle<Screen>& screen);

    protected:
      bool doDeserialize(const tinyxml2::XMLElement* element) override;
      void doSerialize(tinyxml2::XMLElement* element) const override;

    private:
      HandleField<Resources::Texture2D>* m_texture;
      ValueField<float>* m_hullStrength;
	    Shield* m_shield;
      std::vector<Turret*> m_turrets;

      Handle<GameObject> m_gameObject;
  };
}