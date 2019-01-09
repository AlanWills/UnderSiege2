#include "stdafx.h"

#include "Turrets/AimControl/AutomaticAimController.h"
#include "Objects/GameObject.h"
#include "Level/Level.h"
#include "Maths/MathsUtils.h"


namespace US
{
  REGISTER_SCRIPT(AutomaticAimController, 10)

  //------------------------------------------------------------------------------------------------
  AutomaticAimController::AutomaticAimController() :
    m_targetType(ShipType::kPlayer),
    m_targetShip()
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

    if (m_targetShip.is_null())
    {
      std::vector<Ship*> targetShips;
      Level::current()->getShipManager()->getShipsOfType(m_targetType, targetShips);

      if (!targetShips.empty())
      {
        m_targetShip = targetShips.front()->getGameObject();
      }
    }
    else
    {
      getTransform()->setWorldRotation(Maths::lookAt(getTransform()->getWorldTranslation(), m_targetShip->getTransform()->getWorldTranslation()));
    }
  }
}