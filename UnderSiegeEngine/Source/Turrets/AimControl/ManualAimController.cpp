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
    const glm::vec3& cameraWorldTranslation = getGameObject()->getOwnerScreen()->getWorldLayer().getCamera().getTransform()->getWorldTranslation();

    float mouseWorldSpaceX = mouseScreenPosition.x + cameraWorldTranslation.x;
    float mouseWorldSpaceY = mouseScreenPosition.y + cameraWorldTranslation.y;
    float angle = Maths::lookAt(worldTranslation, glm::vec2(mouseWorldSpaceX, mouseWorldSpaceY));

    getTransform()->setWorldRotation(angle);
  }
}