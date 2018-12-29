#include "stdafx.h"

#include "Turrets/Turret.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Objects/GameObject.h"
#include "Turrets/TurretController.h"
#include "Animation/Animator.h"
#include "Bullets/Bullet.h"
#include "Rendering/SpriteRenderer.h"
#include "Animation/Animator.h"

using namespace CelesteEngine::Resources;


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Turret)

  //------------------------------------------------------------------------------------------------
  Turret::Turret() :
    m_damage(createValueField<float>("damage", 0)),
    m_fireRate(createValueField<float>("fire_rate", 1)),
    m_turretSprite(createReferenceField<Path>("turret_sprite")),
    m_turretSpriteSheetDimensions(createReferenceField<glm::uvec2>("turret_sprite_sheet_dimensions")),
    m_turretPrefab(createReferenceField<Path>("turret_prefab")),
    m_bulletAsset(createReferenceField<Path>("bullet"))
  {
  }

  //------------------------------------------------------------------------------------------------
  bool Turret::doDeserialize(const tinyxml2::XMLElement* element)
  {
    m_bullet = ScriptableObject::load<Bullet>(m_bulletAsset->getValue());
    if (m_bullet == nullptr)
    {
      ASSERT_FAIL();
      return false;
    }

    m_bullet->setTurret(this);

    return true;
  }

  //------------------------------------------------------------------------------------------------
  Handle<GameObject> Turret::create(const Handle<Screen>& screen) const
  {
    const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(m_turretPrefab->getValue());
    if (prefab.is_null())
    {
      ASSERT_FAIL();
      return Handle<GameObject>();
    }

    Handle<GameObject> gameObject = prefab->instantiate(screen);
    gameObject->findComponent<TurretController>()->setTurret(this);
    gameObject->findComponent<Rendering::SpriteRenderer>()->setTexture(getTurretSprite());
    gameObject->findComponent<Animation::Animator>()->setSpriteSheetDimensions(getTurretSpriteSheetDimensions());

    return gameObject;
  }
}