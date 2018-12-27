#include "stdafx.h"

#include "Bullets/BulletController.h"
#include "Objects/GameObject.h"
#include "Physics/Collider.h"
#include "Ships/ShipController.h"
#include "Bullets/Bullet.h"
#include "Turrets/Turret.h"
#include "Screens/Screen.h"


namespace US
{
  REGISTER_SCRIPT(BulletController, 10)

  //------------------------------------------------------------------------------------------------
  BulletController::BulletController() :
    m_bullet(nullptr)
  {
  }

  //------------------------------------------------------------------------------------------------
  BulletController::~BulletController()
  {
  }

  //------------------------------------------------------------------------------------------------
  void BulletController::onTriggerEnter(const Handle<Physics::Collider>& collider)
  {
    if (collider->getGameObject()->getTag() == internString("Ship"))
    {
      const Handle<ShipController>& shipController = collider->getGameObject()->findComponent<ShipController>();
      if (shipController->getShip() != m_bullet->getTurret()->getShip())
      {
        const Handle<GameObject>& gameObject = m_bullet->createExplosion(getGameObject()->getOwnerScreen());
        gameObject->getTransform()->setWorldTranslation(getGameObject()->getTransform()->getWorldTranslation());

        // Remove from physics simulation (somehow)
        // Change scripts to only die in game object death function
        // Then this might work?
        // Could also manually get each bullet to check rather than relying on physics?

        getGameObject()->die();

        // Damage the ship we have just hit
        shipController->damage(m_damage);
      }
    }
  }

  //------------------------------------------------------------------------------------------------
  void BulletController::onDeath()
  {
    Inherited::onDeath();

    m_bullet = nullptr;
  }

  //------------------------------------------------------------------------------------------------
  void BulletController::setBullet(const Bullet* bullet)
  {
    m_bullet = bullet;
    
    if (m_bullet != nullptr)
    {
      m_damage = m_bullet->getDamage();
    }
  }
}