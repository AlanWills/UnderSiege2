#include "stdafx.h"

#include "Bullets/BulletController.h"
#include "Objects/GameObject.h"
#include "Physics/Collider.h"
#include "Ships/ShipController.h"
#include "Bullets/Bullet.h"
#include "Turrets/Turret.h"
#include "Screens/Screen.h"
#include "Rendering/SpriteRenderer.h"
#include "Animation/SpriteSheetAnimation.h"


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
  void BulletController::onTriggerEnter(const ConstHandle<Physics::Collider>& collider)
  {
    if (collider->getGameObject()->getTag() == internString("Ship"))
    {
      const ConstHandle<ShipController>& shipController = collider->getGameObject()->findComponent<ShipController>();
      if (shipController->getShip() != m_bullet->getTurret()->getShip())
      {
        const Handle<GameObject>& gameObject = m_bullet->createExplosion(getGameObject()->getOwnerScreen());
        gameObject->getTransform()->setWorldTranslation(getGameObject()->getTransform()->getWorldTranslation());

        // How do we defer kill this game object?
        // Remove from simulation?  But we are iterating over it.
        // Need this function call after all the physics calculation has taken place.
        // Maybe let entire physics calculation happen then resolve function calls

        //getGameObject()->die();
      }
    }
  }

  //------------------------------------------------------------------------------------------------
  void BulletController::onDeath()
  {
    Inherited::onDeath();

    m_bullet = nullptr;
  }
}