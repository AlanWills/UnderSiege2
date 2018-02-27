#include "stdafx.h"

#include "Ships/Ship.h"
#include "Screens/Screen.h"
#include "Resources/ResourceManager.h"
#include "Resources/Prefab.h"
#include "Registries/ScriptableObjectRegistry.h"


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Ship)

  //------------------------------------------------------------------------------------------------
  Ship::Ship() :
    m_hullStrength(createValueField<float>("hull_strength")),
    m_gameObject()
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

    const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(Path("Ships", "PlayerShip.xml"));
    if (prefab.is_null())
    {
      ASSERT_FAIL();
      return m_gameObject;
    }

    m_gameObject = prefab->instantiate(screen);
    return m_gameObject;                                                                                                                                                                                                                                                                                                                                                                                                                 
  }
}