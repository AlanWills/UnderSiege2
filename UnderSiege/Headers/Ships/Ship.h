#pragma once

#include "Objects/ScriptableObject.h"


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

    float getHullStrength() const { return m_hullStrength->getValue(); }

    Handle<GameObject> create(const Handle<Screen>& screen);

  private:
    ValueField<float>* m_hullStrength;

    Handle<GameObject> m_gameObject;
};

}