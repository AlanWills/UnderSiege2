#pragma once

#include "Objects/Script.h"
#include "Resources/2D/Texture2D.h"


namespace US
{
  namespace RayTracing
  {
    class RayTracer : public CelesteEngine::Script
    {
      DECLARE_SCRIPT(RayTracer)

      protected:
        void onHandleInput() override;
        void onDeath() override;

      private:
        using Inherited = CelesteEngine::Script;

        void raycast();

        PinnedHandle<CelesteEngine::Resources::Texture2D> m_texture;
    };
  }
}