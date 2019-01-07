#include "stdafx.h"

#include "Turrets/AimControl/ManualAimController.h"
#include "Objects/GameObject.h"
#include "Input/InputUtils.h"
#include "Input/Mouse.h"
#include "Viewport/Camera.h"
#include "Screens/Screen.h"
#include "Maths/MathsUtils.h"


namespace US
{
  REGISTER_SCRIPT(ManualAimController, 2)

  //------------------------------------------------------------------------------------------------
  ManualAimController::ManualAimController()
  {
  }

  //------------------------------------------------------------------------------------------------
  ManualAimController::~ManualAimController()
  {
  }

  //------------------------------------------------------------------------------------------------
  void ManualAimController::onUpdate(float elapsedGameTime)
  {
    Inherited::onUpdate(elapsedGameTime);

    const glm::vec3& worldTranslation = getTransform()->getWorldTranslation();
    glm::vec2 mouseScreenPosition = CelesteEngine::Input::getMouse().getScreenPosition();
    float angle = Maths::lookAt(worldTranslation, glm::vec2(mouseScreenPosition.x, mouseScreenPosition.y));

    getTransform()->setWorldRotation(angle);
  }
}