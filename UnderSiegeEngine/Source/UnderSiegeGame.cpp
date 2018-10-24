#include "stdafx.h"

#include "UnderSiegeGame.h"
#include "Settings/GameSettings.h"
#include "Screens/Loading/ScreenLoader.h"
#include "Lua/LuaState.h"
#include "Lua/LuaManifest.h"


namespace US
{
  //------------------------------------------------------------------------------------------------
  void UnderSiegeGame::onInitialize()
  {
    Inherited::onInitialize();

    std::unique_ptr<Settings::GameSettings> settings(ScriptableObject::load<Settings::GameSettings>(Path("Data", "Settings", "GameSettings.asset")));
    if (settings == nullptr)
    {
      settings.reset(new Settings::GameSettings());
    }

    if (!Lua::LuaState::script(Path(getResourcesDirectory(), "Scripts", "Core", "FileSystem", "Path.lua")))
    {
      ASSERT_FAIL();
    }

    Lua::LuaState::script(Path(getResourcesDirectory(), "Scripts", "Game.lua"));
  }
}