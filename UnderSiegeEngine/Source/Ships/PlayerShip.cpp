#include "stdafx.h"

#include "Ships/PlayerShip.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Turrets/AimControl/ManualAimController.h"
#include "Turrets/FireControl/ManualFireController.h"


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(PlayerShip)

  //------------------------------------------------------------------------------------------------
  PlayerShip::PlayerShip()
  {
  }

  //------------------------------------------------------------------------------------------------
  void PlayerShip::onCreate(const Handle<GameObject>& gameObject) const
  {
    size_t turretCounter = 0;

    for (size_t i = 0; i < gameObject->getChildCount(); ++i)
    {
      Handle<GameObject> turretGameObject = gameObject->getChildGameObject(i);
      if (turretGameObject->getTag() == internString("Turret"))
      {
        Turret* turret = getTurrets()[turretCounter++];

        turretGameObject->addComponent<ManualAimController>();
        turretGameObject->addComponent<ManualFireController>()->setTurret(turret);
      }
    }
  }
}