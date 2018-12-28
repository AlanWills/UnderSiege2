#pragma once

#include "Objects/Script.h"
#include "UnderSiegeEngineDllExport.h"


namespace US
{
  class Shield;

  class UnderSiegeEngineDllExport ShieldController : public CelesteEngine::Script
  {
    DECLARE_SCRIPT(ShieldController)

    public:
      const Shield* getShield() const { return m_shield; }
      void setShield(const Shield* shield);

      float getShieldStrength() const { return m_shieldStrength; }

      void damage(float damage);

    protected:
      void onDeath() override;

    private:
      using Inherited = CelesteEngine::Script;

      const Shield* m_shield;
      float m_shieldStrength;
  };
}