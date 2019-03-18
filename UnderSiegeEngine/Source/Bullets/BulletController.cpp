#include "stdafx.h"

#include "Bullets/BulletController.h"
#include "Objects/GameObject.h"
#include "Physics/Collider.h"
#include "Ships/ShipController.h"
#include "Shields/ShieldController.h"
#include "Shields/Shield.h"
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
    // Tidy this up

    if (collider->getGameObject()->getTag() == internString("Ship"))
    {
      const Handle<ShipController>& shipController = collider->getGameObject()->findComponent<ShipController>();
      if (shipController->getShip() != m_bullet->getTurret()->getShip())
      {
        const Handle<GameObject>& gameObject = m_bullet->createExplosion(getGameObject()->getScreen());
        gameObject->getTransform()->setWorldTranslation(getGameObject()->getTransform()->getWorldTranslation());

        // Damage the ship we have just hit
        shipController->damage(m_damage);

        // Kill this bullet
        getGameObject()->die();
      }
    }
    else if (collider->getGameObject()->getTag() == internString("Shield"))
    {
      const Handle<ShieldController>& shieldController = collider->getGameObject()->findComponent<ShieldController>();
      if (shieldController->getShield()->getShip() != m_bullet->getTurret()->getShip())
      {
        const Handle<GameObject>& gameObject = m_bullet->createExplosion(getGameObject()->getScreen());
        gameObject->getTransform()->setWorldTranslation(getGameObject()->getTransform()->getWorldTranslation());

        // Damage the ship we have just hit
        shieldController->damage(m_damage);

        // Kill this bullet
        getGameObject()->die();
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