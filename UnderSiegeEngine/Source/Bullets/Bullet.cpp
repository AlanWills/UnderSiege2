#include "stdafx.h"

#include "Bullets/Bullet.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Rendering/SpriteRenderer.h"

using namespace CelesteEngine::Resources;


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Bullet)

  //------------------------------------------------------------------------------------------------
  Bullet::Bullet() :
    m_speed(createValueField<float>("speed")),
    m_texture(createHandleField<Resources::Texture2D>("texture")),
    m_bulletPrefab(createReferenceField<Path>("bullet_prefab"))
  {
  }

  //------------------------------------------------------------------------------------------------
  Handle<GameObject> Bullet::create(const Handle<Screen>& screen) const
  {
    const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(m_bulletPrefab->getValue());
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