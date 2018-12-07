#include "stdafx.h"

#include "Shields/Shield.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Serialization/MathsSerializers.h"
#include "Resources/Data/Prefab.h"
#include "Rendering/SpriteRenderer.h"

using namespace CelesteEngine::Resources;


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Shield)

  //------------------------------------------------------------------------------------------------
  Shield::Shield() :
    m_strength(createValueField("strength", 100)),
    m_rechargePerSecond(createValueField("recharge_per_second", 1)),
    m_texture(createHandleField<Resources::Texture2D>("texture")),
    m_colour(createReferenceField("colour", glm::vec3(1))),
    m_shieldPrefab(createReferenceField<Path>("shield_prefab"))
  {
  }

  //------------------------------------------------------------------------------------------------
  Handle<GameObject> Shield::create(const Handle<Screen>& screen) const
  {
    const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(m_shieldPrefab->getValue());
    if (prefab.is_null())
    {
      ASSERT_FAIL();
      return Handle<GameObject>();
    }

    Handle<GameObject> gameObject = prefab->instantiate(screen);
    gameObject->findComponent<Rendering::SpriteRenderer>()->setTexture(m_texture->getValue());

    return gameObject;
  }
}