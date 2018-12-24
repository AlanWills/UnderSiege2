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

<<<<<<< HEAD
    Lua::LuaState::script(Path(Resources::getResourcesDirectory(), "Scripts", "DataConverters", "Animation", "AnimatorDataConverter.lua"));
=======
    Lua::LuaState::script(Path(Resources::getResourcesDirectory(), "Scripts", "DataConverters", "Animation", "AnimationDataConverter.lua"));
>>>>>>> de79c8c... Updating submodules and fixing up after sprite sheet animation refactoring
    Lua::LuaState::script(Path(Resources::getResourcesDirectory(), "Scripts", "Game.lua"));
  }
}
