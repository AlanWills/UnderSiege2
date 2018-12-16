#include "stdafx.h"

#include "Bullets/Bullet.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Rendering/SpriteRenderer.h"
#include "Physics/PhysicsManager.h"
#include "Physics/RectangleCollider.h"
#include "Bullets/BulletController.h"
#include "Screens/Screen.h"

using namespace CelesteEngine::Resources;


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Bullet)

  //------------------------------------------------------------------------------------------------
  Bullet::Bullet() :
    m_speed(createValueField<float>("speed")),
    m_texture(createHandleField<Resources::Texture2D>("texture")),
    m_bulletPrefab(createReferenceField<Path>("bullet_prefab")),
    m_explosionPrefab(createReferenceField<Path>("explosion_prefab"))
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
    gameObject->findComponent<BulletController>()->setBullet(this);

    const Handle<Physics::RectangleCollider>& collider = gameObject->findComponent<Physics::RectangleCollider>();
    collider->setDimensions(gameObject->findComponent<Rendering::SpriteRenderer>()->getDimensions());

    Physics::addSimulatedBody(collider.as<Physics::Collider>());

    return gameObject;
  }

  //------------------------------------------------------------------------------------------------
  Handle<GameObject> Bullet::createExplosion(const Handle<Screen>& screen) const
  {
    const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(m_explosionPrefab->getValue());
    if (prefab.is_null())
    {
      ASSERT_FAIL();
      return Handle<GameObject>();
    }

    return prefab->instantiate(screen);
  }
}