#include "stdafx.h"

#include "Turrets/AimControl/AutomaticAimController.h"
#include "Objects/GameObject.h"


namespace US
{
  REGISTER_SCRIPT(AutomaticAimController, 10)

  //------------------------------------------------------------------------------------------------
  AutomaticAimController::AutomaticAimController()
  {
  }

  //------------------------------------------------------------------------------------------------
  AutomaticAimController::~AutomaticAimController()
  {
  }

  //------------------------------------------------------------------------------------------------
  void AutomaticAimController::onUpdate(float elapsedGameTime)
  {
    Inherited::onUpdate(elapsedGameTime);
  }
}