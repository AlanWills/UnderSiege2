#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/ScriptableObject.h"


namespace US
{

class UnderSiegeEngineDllExport Turret : public CelesteEngine::ScriptableObject
{
  DECLARE_SCRIPTABLE_OBJECT(Turret)

  public:
    Turret();

    float getFireRate() const { return m_fireRate->getValue(); }

  private:
    ValueField<int>* m_damage;
    ValueField<float>* m_fireRate;
    ReferenceField<std::string>* m_bullet;
    ReferenceField<std::vector<Handle<Texture2D>>>* m_firingAnimationFrames;
};

}