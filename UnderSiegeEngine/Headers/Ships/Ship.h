#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/ScriptableObject.h"
#include "Resources/Texture2D.h"
#include "Shields/Shield.h"


namespace CelesteEngine
{
  class Screen;
}

namespace US
{

class UnderSiegeEngineDllExport Ship : public CelesteEngine::ScriptableObject
{
  DECLARE_SCRIPTABLE_OBJECT(Ship)

  public:
    Ship();

    const Handle<Texture2D>& getTexture() const { return m_texture->getValue(); }
    float getHullStrength() const { return m_hullStrength->getValue(); }

    Handle<GameObject> create(const Handle<Screen>& screen);

  private:
    HandleField<Texture2D>* m_texture;
    ValueField<float>* m_hullStrength;
	Shield* m_shield;

    Handle<GameObject> m_gameObject;
};

}