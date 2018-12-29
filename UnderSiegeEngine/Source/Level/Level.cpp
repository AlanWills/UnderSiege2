#include "stdafx.h"

#include "Level/Level.h"
#include "Screens/Screen.h"
#include "Screens/Loading/ScreenLoader.h"
#include "Rendering/SpriteRenderer.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Serialization/MathsSerializers.h"
#include "Deserialization/MathsDeserializers.h"
#include "Ships/EnemyShip.h"


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Level)

  std::unique_ptr<Level> Level::m_current = std::unique_ptr<Level>();

  //------------------------------------------------------------------------------------------------
  Level::Level() :
    Inherited(),
    m_screen(),
    m_playerShip(),
    m_screenFilePath(createReferenceField("screen_file_path", Path(""))),
    m_backgroundFilePath(createReferenceField("background_file_path", Path(""))),
    m_playerSpawnPosition(createReferenceField<glm::vec2>("player_spawn_position"))
  {
  }

  //------------------------------------------------------------------------------------------------
  void Level::makeCurrent()
  {
    // Load the level
    m_current.reset(this);
    ASSERT(m_current.get());

    if (m_current.get() != nullptr)
    {
      // Load the screen file for this level
      m_current->m_screen = ScreenLoader::load(Path(Resources::getResourcesDirectory(), m_current->getScreenFilePath()));

      // Set up the background
      m_current->setBackground();

      // Now load the current player ship configuration
      m_current->setPlayer();

      EnemyShip* enemy = ScriptableObject::load<EnemyShip>(Path("Data", "Enemies", "Fiirkan.asset"));
      Handle<GameObject> enemyGameObject = enemy->create(m_current->m_screen);
      enemyGameObject->getTransform()->setTranslation(100, getViewportDimensions().y * 0.5f);
    }
  }

  //------------------------------------------------------------------------------------------------
  void Level::setBackground() const
  {
    const Handle<GameObject>& background = m_screen->findGameObjectWithName("Background");
    ASSERT(!background.is_null());

    background->findComponent<Rendering::SpriteRenderer>()->setTexture(getBackgroundFilePath());
    ASSERT(!background->findComponent<Rendering::SpriteRenderer>()->getTexture().is_null());
  }

  //------------------------------------------------------------------------------------------------
  void Level::setPlayer() const
  {
    m_current->m_playerShip.reset(ScriptableObject::load<PlayerShip>(Path("Data", "Player", "PlayerShip.asset")));
    ASSERT(m_current->m_playerShip.get());

    // Create the player game object
    const Handle<GameObject>& playerShip = m_current->m_playerShip->create(m_current->m_screen);
    ASSERT(!playerShip.is_null());

    // Set the player's starting location
    playerShip->getTransform()->setTranslation(m_current->m_playerSpawnPosition->getValue());
  }
}