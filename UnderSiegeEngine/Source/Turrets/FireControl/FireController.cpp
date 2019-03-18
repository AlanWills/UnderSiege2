#include "stdafx.h"

#include "Turrets/FireControl/FireController.h"
#include "Objects/GameObject.h"
#include "Input/InputUtils.h"
#include "Animation/Animator.h"
#include "Screens/Screen.h"
#include "Physics/RigidBody2D.h"
#include "Turrets/Turret.h"
#include "Bullets/Bullet.h"


namespace US
{
  //------------------------------------------------------------------------------------------------
  FireController::FireController() :
    m_turret(nullptr),
    m_turretAnimation(),
    m_currentFireTimer(0),
    m_isFiring(false)
  {
  }

  //------------------------------------------------------------------------------------------------
  void FireController::onSetGameObject(const Handle<GameObject>& gameObject)
  {
    Inherited::onSetGameObject(gameObject);

    m_turretAnimation = gameObject->findComponent<Animation::Animator>();
  }

  //------------------------------------------------------------------------------------------------
  void FireController::onUpdate(float elapsedGameTime)
  {
    Inherited::onUpdate(elapsedGameTime);

    m_currentFireTimer = std::min(m_currentFireTimer + elapsedGameTime, m_turret->getFireRate());

    if (m_isFiring)
    {
      tryFire();
    }
    else
    {
      m_turretAnimation->pause();
    }
  }

  //------------------------------------------------------------------------------------------------
  void FireController::onDeath()
  {
    Inherited::onDeath();

    m_turret = nullptr;
    m_turretAnimation.reset();
    m_currentFireTimer = 0;
    m_isFiring = false;
  }

  //------------------------------------------------------------------------------------------------
  void FireController::tryFire()
  {
    if (m_currentFireTimer >= m_turret->getFireRate())
    {
      m_turretAnimation->play();

      const Handle<GameObject>& bullet = m_turret->getBullet()->create(getGameObject()->getScreen());
      bullet->getTransform()->setTranslation(getTransform()->getWorldTranslation());

      float worldRotation = getTransform()->getWorldRotation();
      bullet->getTransform()->setRotation(worldRotation);

      float speed = m_turret->getBullet()->getSpeed();
      const Handle<Physics::RigidBody2D>& rigidBody = bullet->findComponent<Physics::RigidBody2D>();
      rigidBody->setLinearVelocity(speed * std::sin(worldRotation), speed * std::cos(worldRotation));

      m_currentFireTimer = 0;
    }
  }
}