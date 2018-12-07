#include "stdafx.h"

#include "Turrets/TurretController.h"
#include "Objects/GameObject.h"
#include "Input/InputUtils.h"
#include "Animation/Animation.h"
#include "Screens/Screen.h"
#include "Physics/RigidBody2D.h"
#include "Turrets/Turret.h"
#include "Bullets/Bullet.h"


namespace US
{
  REGISTER_COMPONENT(TurretController, 10)

  //------------------------------------------------------------------------------------------------
  TurretController::TurretController() :
    m_turret(nullptr),
    m_turretAnimation(),
    m_currentFireTimer(0)
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

      if (m_currentFireTimer >= m_turret->getFireRate())
      {
        const Handle<GameObject>& bullet = m_turret->getBullet()->create(getGameObject()->getOwnerScreen());
        bullet->getTransform()->setTranslation(getTransform()->getWorldTranslation());

        float worldRotation = getTransform()->getWorldRotation();
        bullet->getTransform()->setRotation(worldRotation);

        float speed = m_turret->getBullet()->getSpeed();
        const Handle<Physics::RigidBody2D>& rigidBody = bullet->findComponent<Physics::RigidBody2D>();
        rigidBody->setLinearVelocity(speed * std::sin(worldRotation), speed * std::cos(worldRotation));

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