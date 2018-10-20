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

    CelesteEngine::Lua::LuaState::instance().script_file("C:\\Repos\\UnderSiege2\\UnderSiege\\bin\\x64\\Debug\\script.lua");

    ScreenLoader::load(Path(getResourcesDirectory(), "Data", "Screens", "PersistentStartupAndMainMenu.asset"));
    Handle<Screen> screen = ScreenLoader::load(Path(getResourcesDirectory(), "Data", "Screens", "SplashScreen.asset"));
    Handle<GameObject> gameObject = screen->allocateGameObject(Layer::kGUI);
    Handle<Lua::LuaComponent> luaComponent = Lua::LuaManifest::addComponent("Test", gameObject);
  }
}