#include "stdafx.h"

#include "Ships/EnemyShip.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Turrets/AimControl/AutomaticAimController.h"
#include "Turrets/FireControl/AutomaticFireController.h"


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(EnemyShip)

  //------------------------------------------------------------------------------------------------
  EnemyShip::EnemyShip()
  {
  }

  //------------------------------------------------------------------------------------------------
  void EnemyShip::onCreate(const Handle<GameObject>& gameObject) const
  {
    size_t turretCounter = 0;

    for (size_t i = 0; i < gameObject->getChildCount(); ++i)
    {
      Handle<GameObject> turretGameObject = gameObject->getChildGameObject(i);
      if (turretGameObject->getTag() == internString("Turret"))
      {
        Turret* turret = getTurrets()[turretCounter++];

        turretGameObject->addComponent<AutomaticAimController>();
        turretGameObject->addComponent<AutomaticFireController>()->setTurret(turret);
      }
    }
  }
}