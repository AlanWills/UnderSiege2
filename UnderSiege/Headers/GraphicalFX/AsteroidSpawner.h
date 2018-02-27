#pragma once

#include "Objects/Script.h"


namespace US
{

class AsteroidSpawner : public CelesteEngine::Script 
{
  DECLARE_SCRIPT(AsteroidSpawner)

  public:
    void spawn(const Path& asteroidPath, size_t numberToSpawn);

  protected:
    void onUpdate(float elapsedGameTime) override;
    void onDeath() override;

  private:
    typedef CelesteEngine::Script Inherited;
    typedef std::vector<Handle<GameObject>> Asteroids;

    std::vector<Handle<GameObject>> m_asteroids;
};

}