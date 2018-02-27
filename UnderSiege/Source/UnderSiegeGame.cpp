#include "stdafx.h"

#include "UnderSiegeGame.h"
#include "Audio/AudioSource.h"
#include "Settings/GameSettings.h"
#include "Screens/Loading/ScreenLoader.h"


namespace US
{
  //------------------------------------------------------------------------------------------------
  void UnderSiegeGame::onInitialize()
  {
    Inherited::onInitialize();

    std::unique_ptr<Settings::GameSettings> settings(ScriptableObject::load<Settings::GameSettings>(Path("Settings", "GameSettings.xml")));
    if (settings == nullptr)
    {
      settings.reset(new Settings::GameSettings());
    }

    getAudioManager()->setMasterVolume(settings->getMasterVolume());
    getAudioManager()->setMusicVolume(settings->getMusicVolume());
    getAudioManager()->setSFXVolume(settings->getSFXVolume());

    ScreenLoader::load(Path(getResourceManager()->getDataDirectoryPath(), "Screens", "PersistentStartupAndMainMenu.xml"));
    ScreenLoader::load(Path(getResourceManager()->getDataDirectoryPath(), "Screens", "SplashScreen.xml"));
  }
}