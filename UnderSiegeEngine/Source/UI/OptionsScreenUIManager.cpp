#include "stdafx.h"

#include "UI/OptionsScreenUIManager.h"
#include "Objects/GameObject.h"
#include "Screens/Screen.h"
#include "UI/Slider.h"
#include "UI/Button.h"
#include "Rendering/TextRenderer.h"
#include "Audio/AudioManager.h"
#include "Settings/GameSettings.h"
#include "Resources/ResourceManager.h"

using namespace CelesteEngine::UI;
using namespace CelesteEngine::Rendering;
using namespace CelesteEngine::Audio;


namespace US
{
  REGISTER_SCRIPT(OptionsScreenUIManager, 1);

  //------------------------------------------------------------------------------------------------
  OptionsScreenUIManager::OptionsScreenUIManager()
  {
  }

  //------------------------------------------------------------------------------------------------
  OptionsScreenUIManager::~OptionsScreenUIManager()
  {
  }

  //------------------------------------------------------------------------------------------------
  void OptionsScreenUIManager::onSetGameObject(const Handle<GameObject>& gameObject)
  {
    Inherited::onSetGameObject(gameObject);

    const Handle<Screen>& screen = gameObject->getScreen();
    if (screen.is_null())
    {
      ASSERT_FAIL();
      return;
    }

    initializeMasterVolumeSlider(screen);
    initializeMusicVolumeSlider(screen);
    initializeSFXVolumeSlider(screen);
    initializeCloseButton(screen);
  }

  //------------------------------------------------------------------------------------------------
  void OptionsScreenUIManager::initializeMasterVolumeSlider(const Handle<Screen>& screen)
  {
    const Handle<Slider>& slider = screen->findGameObject("MasterVolumeSlider")->findComponent<Slider>();
    slider->subscribeValueChangedCallback([](EventArgs& e, const Handle<GameObject>& go, float newValue) -> void
    {
      const Handle<GameObject>& sliderLabel = go->findChildGameObject("MasterVolumeValueText");
      sliderLabel->findComponent<TextRenderer>()->setLine(0, std::to_string(static_cast<int>(newValue * 100.0f)));
      getAudioManager()->setMasterVolume(newValue);
    });
    slider->setCurrentValue(getAudioManager()->getMasterVolume());
  }

  //------------------------------------------------------------------------------------------------
  void OptionsScreenUIManager::initializeMusicVolumeSlider(const Handle<Screen>& screen)
  {
    const Handle<Slider>& slider = screen->findGameObject("MusicVolumeSlider")->findComponent<Slider>();
    slider->subscribeValueChangedCallback([](EventArgs& e, const Handle<GameObject>& go, float newValue) -> void
    {
      const Handle<GameObject>& sliderLabel = go->findChildGameObject("MusicVolumeValueText");
      sliderLabel->findComponent<TextRenderer>()->setLine(0, std::to_string(static_cast<int>(newValue * 100.0f)));
      getAudioManager()->setMusicVolume(newValue);
    });
    slider->setCurrentValue(getAudioManager()->getMusicVolume());
  }

  //------------------------------------------------------------------------------------------------
  void OptionsScreenUIManager::initializeSFXVolumeSlider(const Handle<Screen>& screen)
  {
    const Handle<Slider>& slider = screen->findGameObject("SFXVolumeSlider")->findComponent<Slider>();
    slider->subscribeValueChangedCallback([](EventArgs& e, const Handle<GameObject>& go, float newValue) -> void
    {
      const Handle<GameObject>& sliderLabel = go->findChildGameObject("SFXVolumeValueText");
      sliderLabel->findComponent<TextRenderer>()->setLine(0, std::to_string(static_cast<int>(newValue * 100.0f)));
      getAudioManager()->setSFXVolume(newValue);
    });
    slider->setCurrentValue(getAudioManager()->getSFXVolume());
  }

  //------------------------------------------------------------------------------------------------
  void OptionsScreenUIManager::initializeCloseButton(const Handle<Screen>& screen)
  {
    const Handle<Button>& button = screen->findGameObject("CloseButton")->findComponent<Button>();
    button->subscribeLeftClickCallback([](EventArgs& e, const Handle<GameObject>& gameObject) -> void
    {
      // Save changes
      Path settingsPath(Resources::getResourcesDirectory(), "Data", "Settings", "GameSettings.asset");
      std::unique_ptr<Settings::GameSettings> settings(ScriptableObject::load<Settings::GameSettings>(settingsPath));
      if (settings == nullptr)
      {
        settings.reset(new Settings::GameSettings());
      }

      settings->setMasterVolume(getAudioManager()->getMasterVolume());
      settings->setMusicVolume(getAudioManager()->getMusicVolume());
      settings->setSFXVolume(getAudioManager()->getSFXVolume());
      settings->save(settingsPath);
    });
  }
}