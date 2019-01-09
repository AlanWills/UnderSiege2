#include "stdafx.h"

#include "UnderSiegeGame.h"
#include "Settings/GameSettings.h"
#include "Screens/Loading/ScreenLoader.h"
#include "Lua/LuaState.h"
#include "Lua/Components/LuaComponentManifestRegistry.h"


namespace US
{
  //------------------------------------------------------------------------------------------------
  void UnderSiegeGame::onInitialize()
  {
    Inherited::onInitialize();

    Lua::LuaState::script(Path(Resources::getResourcesDirectory(), "Scripts", "Game.lua"));
  }
}