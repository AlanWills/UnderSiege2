#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/Script.h"


namespace CelesteEngine
{
  class Screen;
}

namespace US
{

class UnderSiegeEngineDllExport OptionsScreenUIManager : public CelesteEngine::Script
{
  DECLARE_SCRIPT(OptionsScreenUIManager)

  protected:
    void onSetGameObject(const Handle<GameObject>& gameObject) override;

  private:
    typedef CelesteEngine::Script Inherited;

    void initializeMasterVolumeSlider(const Handle<Screen>& screen);
    void initializeMusicVolumeSlider(const Handle<Screen>& screen);
    void initializeSFXVolumeSlider(const Handle<Screen>& screen);
    void initializeCloseButton(const Handle<Screen>& screen);
};

}