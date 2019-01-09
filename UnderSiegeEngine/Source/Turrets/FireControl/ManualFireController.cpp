#include "stdafx.h"

#include "Turrets/FireControl/ManualFireController.h"
#include "Objects/GameObject.h"
#include "Input/InputUtils.h"


namespace US
{
  REGISTER_SCRIPT(ManualFireController, 2)

  //------------------------------------------------------------------------------------------------
  ManualFireController::ManualFireController()
  {
  }

  //------------------------------------------------------------------------------------------------
  ManualFireController::~ManualFireController()
  {
  }

  //------------------------------------------------------------------------------------------------
  void ManualFireController::onHandleInput()
  {
    Inherited::onHandleInput();

    setIsFiring(Input::isKeyPressed(GLFW_KEY_SPACE));
  }
}