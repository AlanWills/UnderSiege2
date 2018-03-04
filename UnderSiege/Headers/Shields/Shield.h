#pragma once

#include "Objects/ScriptableObject.h"


namespace US
{

class Shield : public CelesteEngine::ScriptableObject
{
  DECLARE_SCRIPTABLE_OBJECT(Shield)

  public:
    Shield();

  private:
    ValueField<int>* m_strength;
    ValueField<int>* m_rechargePerSecond;
    HandleField<Texture2D>* m_texture;
    ReferenceField<glm::vec3>* m_colour;
};

}