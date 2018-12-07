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

    Handle<GameObject> create(const Handle<Screen>& screen);

  private:
    ValueField<int>* m_damage;
    ValueField<float>* m_fireRate;
    ReferenceField<std::string>* m_bullet;
    
    std::vector<Handle<Resources::Texture2D>> m_firingAnimationFrames;
};

}