#include "stdafx.h"

#include "Turrets/TurretController.h"
#include "Objects/GameObject.h"
#include "Input/InputUtils.h"
#include "Animation/Animation.h"
#include "Screens/Screen.h"
#include "Physics/RigidBody2D.h"


namespace US
{
  REGISTER_COMPONENT(TurretController, 10)

  //------------------------------------------------------------------------------------------------
  TurretController::TurretController() :
    m_turretAnimation(),
    m_currentFireTimer(1)
  {
  }

  //------------------------------------------------------------------------------------------------
  TurretController::~TurretController()
  {
  }

  //------------------------------------------------------------------------------------------------
  void TurretController::onSetGameObject(const Handle<GameObject>& gameObject)
  {
    Inherited::onSetGameObject(gameObject);

    m_turretAnimation = gameObject->findComponent<Animation>();
  }

  //------------------------------------------------------------------------------------------------
  void TurretController::onHandleInput()
  {
    Inherited::onHandleInput();

    if (Input::isKeyPressed(GLFW_KEY_SPACE))
    {
      m_turretAnimation->resume();

      if (m_currentFireTimer >= 1)
      {
        const Handle<GameObject>& bullet = getGameObject()->getOwnerScreen()->allocateGameObject(CelesteEngine::Layer::kWorld);
        bullet->getTransform()->setTranslation(getTransform()->getWorldTranslation());

        float worldRotation = getTransform()->getWorldRotation();
        bullet->getTransform()->setRotation(worldRotation);

        const Handle<SpriteRenderer>& spriteRenderer = bullet->addComponent<SpriteRenderer>();
        spriteRenderer->setTexture(Path("Textures", "Bullets", "shell_small.png"));
        const Handle<Physics::RigidBody2D>& rigidBody = bullet->addComponent<Physics::RigidBody2D>();
        rigidBody->setLinearVelocity(700 * std::sin(worldRotation), 700 * std::cos(worldRotation));

        m_currentFireTimer = 0;
      }
    }
    else
    {
      m_turretAnimation->pause();
      m_currentFireTimer = 0;
    }
  }

  //------------------------------------------------------------------------------------------------
  void TurretController::onUpdate(float elapsedGameTime)
  {
    Inherited::onUpdate(elapsedGameTime);

    m_currentFireTimer += elapsedGameTime;
  }

  //------------------------------------------------------------------------------------------------
  void TurretController::onDeath()
  {
    Inherited::onDeath();

    m_turretAnimation.reset();
    m_currentFireTimer = 0;
  }
}