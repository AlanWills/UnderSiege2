#include "stdafx.h"

#include "UnderSiegeGame.h"
#include "Audio/AudioSource.h"
#include "Settings/GameSettings.h"
#include "Screens/Loading/ScreenLoader.h"
#include "Registries/ScriptableObjectRegistry.h"
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

    getAudioManager()->setMasterVolume(settings->getMasterVolume());
    getAudioManager()->setMusicVolume(settings->getMusicVolume());
    getAudioManager()->setSFXVolume(settings->getSFXVolume());

    ScreenLoader::load(Path(getResourcesDirectory(), "Data", "Screens", "PersistentStartupAndMainMenu.asset"));
    ScreenLoader::load(Path(getResourcesDirectory(), "Data", "Screens", "SplashScreen.asset"));

    CelesteEngine::Lua::LuaManifest::instance();
    luaL_dofile(CelesteEngine::Lua::LuaState::instance(), "C:\\Repos\\UnderSiege2\\UnderSiege\\bin\\x64\\Debug\\script.lua");
    lua_pcall(CelesteEngine::Lua::LuaState::instance(), 0, 0, 0);
  }
}