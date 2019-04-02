#pragma once

#include "Game/Game.h"


namespace US
{
  class UnderSiegeGame : public CelesteEngine::Game
  {
    public:
      UnderSiegeGame() { }

    private:
      using Inherited = CelesteEngine::Game;
  };
}