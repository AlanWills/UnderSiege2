#include "stdafx.h"

#include "Debugging/DebugConsole.h"
#include "Objects/GameObject.h"
#include "Input/InputUtils.h"
#include "Screens/Screen.h"
#include "Screens/Loading/ScreenLoader.h"
#include "Level/Level.h"
#include "UI/GUI.h"
#include "UI/Button.h"
#include "Resources/ResourceManager.h"

using Button = CelesteEngine::UI::Button;


namespace US
{
  namespace Debugging
  {
    REGISTER_SCRIPT(DebugConsole, 1)

    //------------------------------------------------------------------------------------------------
    DebugConsole::DebugConsole()
    {
    }

    //------------------------------------------------------------------------------------------------
    DebugConsole::~DebugConsole()
    {
    }

    //------------------------------------------------------------------------------------------------
    void DebugConsole::onSetGameObject(const Handle<GameObject>& gameObject)
    {
      Inherited::onSetGameObject(gameObject);

      const Handle<GameObject>& reloadScreenButton = gameObject->findChildGameObject("ReloadScreenButton");
      const Handle<Button>& button = reloadScreenButton->findComponent<Button>();
      button->getMouseInteractionHandler()->getOnLeftButtonClickedEvent().subscribe([](EventArgs& e, const Handle<GameObject>& go) -> void
      {
        go->getParent()->findComponent<DebugConsole>()->reloadScreen();
      });
    }

    //------------------------------------------------------------------------------------------------
    void DebugConsole::reloadScreen()
    {
      // Kill current screen
      Level::current()->getScreen()->die();

      // Reload screen
      Level::current()->loadScreen();
    }

    //------------------------------------------------------------------------------------------------
    void DebugConsole::reloadPlayer()
    {
      if (Level::current()->getPlayerShip() != nullptr)
      {
        // Cleanup player ship if it already exists
        Level::current()->getShipManager()->removeShip(Level::current()->getPlayerShip());
        Level::current()->getPlayerShip()->getGameObject()->die();
      }

      Level::current()->loadPlayer();
    }

    //------------------------------------------------------------------------------------------------
    void DebugConsole::reloadEnemies()
    {

    }

    //------------------------------------------------------------------------------------------------
    void DebugConsole::reloadGUI()
    {
      Resources::getResourceManager()->unloadAll<Resources::Prefab>();
      Resources::getResourceManager()->unloadAll<Resources::Data>();
      UI::GUI::instance().cleanup();
      Level::current()->loadGUI();
    }
  }
}