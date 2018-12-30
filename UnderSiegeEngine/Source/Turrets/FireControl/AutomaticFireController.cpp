#include "stdafx.h"

#include "Turrets/FireControl/AutomaticFireController.h"
#include "Objects/GameObject.h"
#include "Input/InputUtils.h"


namespace US
{
  REGISTER_SCRIPT(AutomaticFireController, 10)

  //------------------------------------------------------------------------------------------------
  AutomaticFireController::AutomaticFireController()
  {
  }

  //------------------------------------------------------------------------------------------------
  AutomaticFireController::~AutomaticFireController()
  {
  }

  //------------------------------------------------------------------------------------------------
  void AutomaticFireController::onHandleInput()
  {
    Inherited::onHandleInput();

    //setIsFiring(true);
  }
}