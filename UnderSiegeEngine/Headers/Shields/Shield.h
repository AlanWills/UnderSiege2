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

	const Handle<Texture2D>& getTexture() const { return m_texture->getValue(); }

  private:
    ValueField<int>* m_strength;
    ValueField<int>* m_rechargePerSecond;
    HandleField<Texture2D>* m_texture;
    ReferenceField<glm::vec3>* m_colour;
};

}