#pragma once

#include "Game/Game.h"


namespace US
{
  class UnderSiegeGame : public Game
  {
    public:
      UnderSiegeGame() { }

    protected:
      void onInitialize() override;

    private:
      typedef Game Inherited;
  };
}