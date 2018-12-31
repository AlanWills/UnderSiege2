#include "stdafx.h"

#include "UI/GUI.h"
#include "Screens/Screen.h"
#include "Resources/ResourceManager.h"
#include "Level/Level.h"

using namespace CelesteEngine::Resources;


namespace US
{
  namespace UI
  {
    //------------------------------------------------------------------------------------------------
    GUI::GUI() :
      m_turretGUIs(ScriptableObject::create<TurretGUIs>("TurretGUIs"))
    {
    }

    //------------------------------------------------------------------------------------------------
    GUI& GUI::instance()
    {
      static GUI gui;
      return gui;
    }

    //------------------------------------------------------------------------------------------------
    void GUI::setup(const Level* level)
    {
      const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(Path("Prefabs", "UI", "TurretGUIManager.prefab"));
      if (prefab.is_null())
      {
        ASSERT_FAIL();
        return;
      }

      m_turretGUIs->setup(prefab->instantiate(level->getScreen()), level->getPlayerShip()->getTurrets());
    }

    //------------------------------------------------------------------------------------------------
    void GUI::cleanup()
    {
      // Destroy all gui objects here
      m_turretGUIs->getGameObject()->die();
    }
  }
}