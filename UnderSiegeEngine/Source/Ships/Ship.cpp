#include "stdafx.h"

#include "Ships/Ship.h"
#include "Screens/Screen.h"
#include "Resources/ResourceManager.h"
#include "Resources/Data/Prefab.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Rendering/SpriteRenderer.h"
#include "Shields/Shield.h"
#include "Turrets/Turret.h"

using namespace CelesteEngine::Resources;


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Ship)

  //------------------------------------------------------------------------------------------------
  Ship::Ship() :
    m_texture(createHandleField<Resources::Texture2D>("texture")),
    m_hullStrength(createValueField<float>("hull_strength")),
	m_shield(createScriptableObject<Shield>("shield")),
    m_gameObject()
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

    for (auto turretElement : children(turretsElement))
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

    return true;
  }
  
  //------------------------------------------------------------------------------------------------
  void Ship::doSerialize(tinyxml2::XMLElement* element) const
  {
  }

  //------------------------------------------------------------------------------------------------
  Handle<GameObject> Ship::create(const Handle<Screen>& screen)
  {
    if (!m_gameObject.is_null())
    {
      // If the game object for this ship is already allocated, we need to immediately deallocate it
      m_gameObject->deallocate();
      m_gameObject.reset();
    }

    const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(Path("Prefabs", "Ships", "PlayerShip.asset"));
    if (prefab.is_null())
    {
      ASSERT_FAIL();
      return m_gameObject;
    }

    m_gameObject = prefab->instantiate(screen);
    m_gameObject->findComponent<Rendering::SpriteRenderer>()->setTexture(getTexture());
	m_gameObject->findChildGameObject("PlayerShield")->findComponent<Rendering::SpriteRenderer>()->setTexture(m_shield->getTexture());

    return m_gameObject;                                                                                                                                                                                                                                                                                                                                                                                                                 
  }
}