#pragma once

#include "Game/Game.h"


namespace US
{
  namespace RayTracing
  {
    class RayTracingGame : public Game
    {
      public:
        RayTracingGame() { }

      protected:
        void onInitialize() override;

      private:
        typedef Game Inherited;
    };
  }
}