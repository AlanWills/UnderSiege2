#pragma once

#include "Objects/Script.h"
#include "UnderSiegeEngineDllExport.h"


namespace CelesteEngine
{
  namespace Rendering
  {
    class TextRenderer;
  }
}

namespace US
{
  namespace Debugging
  {
    class UnderSiegeEngineDllExport FPSCounter : public CelesteEngine::Script
    {
      DECLARE_SCRIPT(FPSCounter)

      protected:
        void onSetGameObject(const Handle<GameObject>& gameObject) override;
        void onUpdate(float elapsedGameTime) override;

      private:
        using Inherited = CelesteEngine::Script;

        Handle<CelesteEngine::Rendering::TextRenderer> m_textRenderer;
        float m_current;
    };
  }
}