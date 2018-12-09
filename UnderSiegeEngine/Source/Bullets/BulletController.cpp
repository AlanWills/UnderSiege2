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
        const Handle<GameObject>& gameObject = getGameObject()->getOwnerScreen()->allocateGameObject(Layer::kWorld);
        gameObject->getTransform()->setTranslation(getGameObject()->getTransform()->getWorldTranslation());

        const Handle<Rendering::SpriteRenderer>& renderer = gameObject->addComponent<Rendering::SpriteRenderer>();
        renderer->setTexture(Path("Textures", "FX", "Explosions", "Explosion.png"));

        const Handle<SpriteSheetAnimation>& spriteSheetAnimation = gameObject->addComponent<SpriteSheetAnimation>();
        spriteSheetAnimation->setSpriteSheetDimensions(glm::ivec2(4, 4));
        spriteSheetAnimation->setLooping(SpriteSheetAnimation::LoopMode::kLooping);
        spriteSheetAnimation->play();

          
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