#pragma once

#include "Objects/ScriptableObject.h"
#include "Resources/Texture2D.h"


namespace CelesteEngine
{
  class Screen;
}

namespace US
{

class Ship : public CelesteEngine::ScriptableObject
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

    Handle<GameObject> m_gameObject;
};

}