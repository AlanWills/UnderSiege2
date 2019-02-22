#pragma once

#include "Game/Game.h"


namespace US
{
  class UnderSiegeGame : public CelesteEngine::Game
  {
    public:
      UnderSiegeGame() { }

    protected:
      void onInitialize() override;

    private:
      using Inherited = CelesteEngine::Game;
  };
}