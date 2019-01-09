#include "stdafx.h"

#include "Shields/Shield.h"
#include "Shields/ShieldController.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Serialization/MathsSerializers.h"
#include "Deserialization/MathsDeserializers.h"
#include "Resources/Data/Prefab.h"
#include "Rendering/SpriteRenderer.h"
#include "Objects/GameObject.h"
#include "Physics/EllipseCollider.h"
#include "Physics/PhysicsManager.h"

using namespace CelesteEngine::Resources;


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Shield)

  //------------------------------------------------------------------------------------------------
  Shield::Shield() :
    m_strength(createValueField("strength", 100.0f)),
    m_rechargePerSecond(createValueField("recharge_per_second", 1.0f)),
    m_texture(createHandleField<Resources::Texture2D>("texture")),
    m_colour(createReferenceField("colour", glm::vec3(1))),
    m_shieldPrefab(createReferenceField<Path>("shield_prefab")),
    m_gameObject(),
    m_ship(nullptr)
  {
  }

  //------------------------------------------------------------------------------------------------
  Handle<GameObject> Shield::create(const Handle<Screen>& screen, const Ship* ship)
  {
    if (!m_gameObject.is_null())
    {
      ASSERT_FAIL();
      return m_gameObject;
    }

    const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(m_shieldPrefab->getValue());
    if (prefab.is_null())
    {
      ASSERT_FAIL();
      return Handle<GameObject>();
    }

    m_ship = ship;
    m_gameObject = prefab->instantiate(screen);
    m_gameObject->findComponent<ShieldController>()->setShield(this);

    Handle<SpriteRenderer> spriteRenderer = m_gameObject->findComponent<Rendering::SpriteRenderer>();
    spriteRenderer->setTexture(m_texture->getValue());

    Handle<Physics::EllipseCollider> ellipseCollider = m_gameObject->findComponent<Physics::EllipseCollider>();
    ellipseCollider->setDimensions(spriteRenderer->getDimensions());

    return m_gameObject;
  }
}