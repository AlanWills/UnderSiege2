#include "stdafx.h"

#include "UnderSiegeGame.h"
#include "Lua/LuaState.h"


namespace US
{
  //------------------------------------------------------------------------------------------------
  void UnderSiegeGame::onInitialize()
  {
    Inherited::onInitialize();

    Lua::LuaState::scriptFile(Path(Resources::getResourcesDirectory(), "Scripts", "Game.lua"));
  }
}