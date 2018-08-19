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

    const Handle<Texture2D>& getIdleTexture() const { return m_idleTexture->getValue(); }

  private:
    ValueField<int>* m_damage;
    ValueField<int>* m_fireRate;
    HandleField<Texture2D>* m_idleTexture;
    ReferenceField<std::vector<Handle<Texture2D>>>* m_firingAnimationFrames;
};

}