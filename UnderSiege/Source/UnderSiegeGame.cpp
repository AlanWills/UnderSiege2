#include "stdafx.h"

#include "UnderSiegeGame.h"
#include "Audio/AudioSource.h"
#include "Settings/Settings.h"
#include "Screens/Loading/ScreenLoader.h"


namespace US
{
  //------------------------------------------------------------------------------------------------
  void UnderSiegeGame::onInitialize()
  {
    Inherited::onInitialize();

    Settings settings;
    settings.load(Path("Settings", "Settings.xml"));
    getAudioManager()->setMasterVolume(settings.getSetting("MasterVolume", 1.0f));
    getAudioManager()->setMusicVolume(settings.getSetting("MusicVolume", 1.0f));
    getAudioManager()->setSFXVolume(settings.getSetting("SFXVolume", 1.0f));

    ScreenLoader::load(Path(getResourceManager()->getDataDirectoryPath(), "Screens", "PersistentStartupAndMainMenu.xml"));
    ScreenLoader::load(Path(getResourceManager()->getDataDirectoryPath(), "Screens", "SplashScreen.xml"));
  }
}