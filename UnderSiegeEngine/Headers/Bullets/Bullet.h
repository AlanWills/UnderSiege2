#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/ScriptableObject.h"


namespace US
{
  class UnderSiegeEngineDllExport Bullet : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(Bullet)

    public:
      Bullet();

      float getSpeed() const { return m_speed->getValue(); }

      Handle<GameObject> create(const Handle<Screen>& screen) const;

    private:
      ValueField<float>* m_speed;
      HandleField<Resources::Texture2D>* m_texture;
      ReferenceField<Path>* m_bulletPrefab;
  };
}