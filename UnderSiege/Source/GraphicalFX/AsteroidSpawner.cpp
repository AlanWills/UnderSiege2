#include "stdafx.h"

#include "GraphicalFX/AsteroidSpawner.h"
#include "Resources/Prefab.h"
#include "Physics/RectangleCollider.h"
#include "Screens/ScreenUtils.h"
#include "Resources/ResourceManager.h"
#include "Rendering/SpriteRenderer.h"
#include "Physics/RigidBody2D.h"
#include "Maths/RandomGenerator.h"
#include "Time/TimeUtils.h"

using namespace CelesteEngine::Physics;


namespace US
{
  REGISTER_SCRIPT(AsteroidSpawner, 2)

  //------------------------------------------------------------------------------------------------
  AsteroidSpawner::AsteroidSpawner() :
    m_asteroids()
  {
  }

  //------------------------------------------------------------------------------------------------
  AsteroidSpawner::~AsteroidSpawner()
  {
  }

  //------------------------------------------------------------------------------------------------
  void AsteroidSpawner::onUpdate(float elapsedGameTime)
  {
    Inherited::onUpdate(elapsedGameTime);

    Asteroids::iterator it = std::find_if(m_asteroids.begin(), m_asteroids.end(), [](const Handle<GameObject>& asteroid) -> bool 
    { 
      return asteroid->isAlive() && asteroid->isActive(); 
    });

    while (it != m_asteroids.end())
    {
      // Go through all the alive and active asteroids and check they are still within the bounds of the screen
      const Handle<RectangleCollider>& collider = (*it)->findComponent<RectangleCollider>();
      ASSERT(!collider.is_null());

      if (collider->rectangle().left().x >= getViewportDimensions().x)
      {
        // Left hand side of collider has gone past the right hand side of the viewport dimensions
        // So we put it back into the screen on the left hand side
        (*it)->getTransform()->translate(-(getViewportDimensions().x + collider->getDimensions().x), 0);
      }

      ++it;
    }
  }

  //------------------------------------------------------------------------------------------------
  void AsteroidSpawner::onDeath()
  {
    Inherited::onDeath();

    Asteroids::iterator it = std::find_if(m_asteroids.begin(), m_asteroids.end(), [](const Handle<GameObject>& asteroid) -> bool { return asteroid->isAlive(); });
    while (it != m_asteroids.end())
    {
      // Go through all the alive asteroids and kill them
      (*it)->die();
      ++it;
    }

    // Now empty the asteroids array
    m_asteroids.clear();
  }

  //------------------------------------------------------------------------------------------------
  void AsteroidSpawner::spawn(const Path& asteroidPrefabPath, size_t numberToSpawn)
  {
    const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(asteroidPrefabPath);
    if (prefab.is_null())
    {
      ASSERT_FAIL();
      return;
    }

    const GameObjectDataConverter& gameObject = prefab->getGameObjects()[0];
    const std::vector<ComponentDataConverterElement>& components = gameObject.getComponents();
    
    // Check the asteroid has a sprite renderer
    ASSERT(std::find_if(components.begin(), components.end(), [](const ComponentDataConverterElement& element) -> bool
    {
      return element.getElementName() == SpriteRenderer::name();
    }) != components.end());

    // Check the asteroid has a rectangle collider
    ASSERT(std::find_if(components.begin(), components.end(), [](const ComponentDataConverterElement& element) -> bool
    {
      return element.getElementName() == RectangleCollider::name();
    }) != components.end());

    // Check the asteroid has a rigid body 2D
    ASSERT(std::find_if(components.begin(), components.end(), [](const ComponentDataConverterElement& element) -> bool
    {
      return element.getElementName() == RigidBody2D::name();
    }) != components.end());

    // Check the asteroid is in the world layer
    ASSERT(gameObject.getLayer() == kWorld);

    const glm::vec2& viewportDimensions = getViewportDimensions();

    for (size_t count = 0; count < numberToSpawn; ++count)
    {
      // Update the dimensions of the asteroid sprite renderer
      const Handle<GameObject>& asteroid = prefab->instantiate(getGameObject()->getOwnerScreen());
      asteroid->findComponent<RectangleCollider>()->setDimensions(asteroid->findComponent<Rendering::SpriteRenderer>()->getDimensions());
      
      // Randomize the speed and spin of the asteroid
      const Handle<RigidBody2D>& rigidBody = asteroid->findComponent<RigidBody2D>();
      rigidBody->setAngularVelocity(Random::generate(-0.5f, 0.5f));
      rigidBody->setLinearVelocity(Random::generate(10, 100.0f), 0);

      // Randomize the starting position of the asteroid
      asteroid->getTransform()->setTranslation(Random::generate(0, viewportDimensions.x), Random::generate(0, viewportDimensions.y));

      m_asteroids.push_back(asteroid);
    }
  }
}