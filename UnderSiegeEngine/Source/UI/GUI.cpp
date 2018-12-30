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
      m_turretGUIManager(ScriptableObject::create<TurretGUIManager>("TurretGUIManager"))
    {
    }

    //------------------------------------------------------------------------------------------------
    GUI& GUI::instance()
    {
      static GUI gui;
      return gui;
    }

    //------------------------------------------------------------------------------------------------
    void GUI::setup(const std::unique_ptr<Level>& level)
    {
      const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(Path("Prefabs", "UI", "TurretGUIManager.prefab"));
      if (prefab.is_null())
      {
        ASSERT_FAIL();
        return;
      }

      m_turretGUIManager->setup(prefab->instantiate(level->getScreen()), level->getPlayerShip()->getTurrets());
    }
  }
}