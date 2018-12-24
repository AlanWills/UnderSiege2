#include "stdafx.h"

#include "Input/LookAtCursor.h"
#include "Objects/GameObject.h"
#include "Input/InputUtils.h"
#include "Input/Mouse.h"
#include "Viewport/Camera.h"
#include "Screens/Screen.h"


namespace US
{
  namespace Input
  {
    REGISTER_SCRIPT(LookAtCursor, 2)

    //------------------------------------------------------------------------------------------------
    LookAtCursor::LookAtCursor()
    {
    }

    //------------------------------------------------------------------------------------------------
    LookAtCursor::~LookAtCursor()
    {
    }

    //------------------------------------------------------------------------------------------------
    void LookAtCursor::onUpdate(float elapsedGameTime)
    {
      Inherited::onUpdate(elapsedGameTime);

      const glm::vec3& worldTranslation = getTransform()->getWorldTranslation();
      glm::vec2 mouseScreenPosition = CelesteEngine::Input::getMouse().getScreenPosition();
      const glm::vec3& cameraWorldTranslation = getGameObject()->getOwnerScreen()->getWorldLayer().getCamera().getTransform()->getWorldTranslation();

      float mouseWorldSpaceX = mouseScreenPosition.x + cameraWorldTranslation.x;
      float mouseWorldSpaceY = mouseScreenPosition.y + cameraWorldTranslation.y;
      float diffX = mouseWorldSpaceX - worldTranslation.x;
      float diffY = mouseWorldSpaceY - worldTranslation.y;
      float angle = std::atan2f(-diffY, diffX) + glm::half_pi<float>();

      getTransform()->setWorldRotation(angle);
    }
  }
}