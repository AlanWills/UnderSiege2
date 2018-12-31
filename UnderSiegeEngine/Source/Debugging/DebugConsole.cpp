#include "stdafx.h"

#include "Debugging/DebugConsole.h"
#include "Objects/GameObject.h"
#include "Input/InputUtils.h"
#include "Screens/Screen.h"
#include "Screens/Loading/ScreenLoader.h"
#include "Level/Level.h"
#include "UI/GUI.h"
#include "Resources/ResourceManager.h"


namespace US
{
  namespace Debugging
  {
    REGISTER_SCRIPT(DebugConsole, 2)

    //------------------------------------------------------------------------------------------------
    DebugConsole::DebugConsole()
    {
    }

    //------------------------------------------------------------------------------------------------
    DebugConsole::~DebugConsole()
    {
    }

    //------------------------------------------------------------------------------------------------
    void DebugConsole::onHandleInput()
    {
      Inherited::onHandleInput();

      // Change the DebugConsole prefab to have buttons for this instead
      if (Input::isKeyPressed(GLFW_KEY_LEFT_CONTROL))
      {
        if (Input::isKeyTapped(GLFW_KEY_S))
        {
          reloadScreen();
        }
        else if (Input::isKeyTapped(GLFW_KEY_G))
        {
          reloadGUI();
        }
        else if (Input::isKeyTapped(GLFW_KEY_P))
        {
          reloadPlayer();
        }
        else if (Input::isKeyTapped(GLFW_KEY_E))
        {
          reloadEnemies();
        }
      }
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