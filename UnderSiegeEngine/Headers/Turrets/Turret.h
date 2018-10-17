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

  private:
    ValueField<int>* m_damage;
    ValueField<int>* m_fireRate;
    ReferenceField<std::vector<Handle<Texture2D>>>* m_firingAnimationFrames;
};

}