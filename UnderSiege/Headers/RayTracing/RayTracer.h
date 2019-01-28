#pragma once

#include "Objects/Script.h"
#include "Resources/2D/Texture2D.h"
#include "RayTracing/World.h"


namespace US
{
  namespace RayTracing
  {
    class RayTracer : public CelesteEngine::Script
    {
      DECLARE_SCRIPT(RayTracer)

      protected:
        void onHandleInput() override;
        void onUpdate(float elapsedGameTime) override;
        void onDeath() override;

      private:
        using Inherited = CelesteEngine::Script;

        void startRaycast();
        void raycastCurrentLine();

        PinnedHandle<CelesteEngine::Resources::Texture2D> m_texture;
        std::unique_ptr<World> m_world;
        int m_currentLine;
    };
  }
}