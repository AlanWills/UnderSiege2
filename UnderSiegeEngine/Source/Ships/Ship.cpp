#include "stdafx.h"

#include "Ships/Ship.h"
#include "Screens/Screen.h"
#include "Resources/ResourceManager.h"
#include "Resources/Data/Prefab.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Rendering/SpriteRenderer.h"
#include "Shields/Shield.h"
#include "Turrets/Turret.h"
#include "Ships/ShipController.h"
#include "Physics/PhysicsManager.h"
#include "Physics/RectangleCollider.h"

using namespace CelesteEngine::Resources;


namespace US
{
  //------------------------------------------------------------------------------------------------
  Ship::Ship() :
    m_texture(createHandleField<Resources::Texture2D>("texture")),
    m_hullStrength(createValueField<float>("hull_strength")),
    m_shieldAsset(createReferenceField<Path>("shield")),
    m_shipPrefab(createReferenceField<Path>("ship_prefab")),
    m_deathAnimationPrefab(createReferenceField<Path>("death_animation_prefab")),
    m_gameObject(),
    m_shipType(ShipType::kPlayer),
	  m_shield(nullptr),
    m_turrets()
  {
  }

  //------------------------------------------------------------------------------------------------
  bool Ship::doDeserialize(const tinyxml2::XMLElement* element)
  {
    const tinyxml2::XMLElement* turretsElement = element->FirstChildElement("Turrets");
    if (turretsElement == nullptr)
    {
      // This is not an error - the ship simply has no turrets at this point
      return true;
    }

    for (auto turretElement : XML::children(turretsElement))
    {
      const char* elementText = turretElement->GetText();
      if (elementText != nullptr)
      {
        Turret* turret = ScriptableObject::load<Turret>(elementText);
        if (turret != nullptr)
        {
          m_turrets.push_back(turret);
        }
      }
    }

    m_shield = ScriptableObject::load<Shield>(m_shieldAsset->getValue());
    
    return true;
  }
  
  //------------------------------------------------------------------------------------------------
  Handle<GameObject> Ship::create(const Handle<Screen>& screen)
  {
    if (!m_gameObject.is_null())
    {
      ASSERT_FAIL();
      return m_gameObject;
    }

    const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(m_shipPrefab->getValue());
    if (prefab.is_null())
    {
      ASSERT_FAIL();
      return Handle<GameObject>();
    }

    m_gameObject = prefab->instantiate(screen);
    m_gameObject->setParent(screen->findGameObject("Canvas"));
    m_gameObject->findComponent<Physics::RectangleCollider>()->setDimensions(getTexture()->getDimensions());
    m_gameObject->findComponent<Rendering::SpriteRenderer>()->setTexture(getTexture());
    m_gameObject->findComponent<ShipController>()->setShip(this);

    for (Turret* turret : m_turrets)
    {
      const Handle<GameObject>& turretGameObject = turret->create(screen, this);
      turretGameObject->setParent(m_gameObject);
    }

    if (m_shield != nullptr)
    {
      const Handle<GameObject>& shieldGameObject = m_shield->create(screen, this);
      shieldGameObject->setParent(m_gameObject);
    }

    onCreate(m_gameObject);
    return m_gameObject;
  }

  //------------------------------------------------------------------------------------------------
  Handle<GameObject> Ship::createDeathAnimation(const Handle<Screen>& screen) const
  {
    const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(m_deathAnimationPrefab->getValue());
    if (prefab.is_null())
    {
      ASSERT_FAIL();
      return Handle<GameObject>();
    }

    return prefab->instantiate(screen);
  }
}