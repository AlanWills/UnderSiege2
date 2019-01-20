#include "stdafx.h"

#include "UI/TurretGUI.h"
#include "Turrets/Turret.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Rendering/SpriteRenderer.h"
#include "Resources/ResourceManager.h"
#include "Input/MouseInteractionHandler.h"
#include "Turrets/FireControl/FireController.h"

using namespace CelesteEngine::Resources;


namespace US
{
  namespace UI
  {
    REGISTER_SCRIPTABLE_OBJECT(TurretGUI)

    //------------------------------------------------------------------------------------------------
    TurretGUI::TurretGUI() :
      m_gameObject()
    {
    }

    //------------------------------------------------------------------------------------------------
    void TurretGUI::setup(const Handle<GameObject>& gameObject, const Turret* turret)
    {
      m_gameObject = gameObject;

      // Set up background
      {
        const Handle<Input::MouseInteractionHandler>& interaction = gameObject->findComponent<Input::MouseInteractionHandler>();
        interaction->getOnLeftButtonClickedEvent().subscribe([turret](EventArgs& e, Handle<GameObject> gameObject) -> void
        {
          turret->getGameObject()->findComponent<FireController>()->tryFire();
        });
      }

      // Set up turret thumbnail
      {
        const Handle<Texture2D>& texture = getResourceManager()->load<Texture2D>(turret->getTurretSprite());
        const glm::uvec2& spriteSheetDimensions = turret->getTurretSpriteSheetDimensions();
        const glm::vec2& textureDimensions = texture->getDimensions();
        
        const Handle<Rendering::SpriteRenderer>& spriteRenderer = m_gameObject->findChildGameObject("TurretSprite")->findComponent<Rendering::SpriteRenderer>();
        spriteRenderer->setTexture(turret->getTurretSprite());
        spriteRenderer->getScissorRectangle().setDimensions(textureDimensions.x / spriteSheetDimensions.x, textureDimensions.y / spriteSheetDimensions.y);
        spriteRenderer->setOrigin(0.5f / spriteSheetDimensions.x, (spriteSheetDimensions.y - 0.5f) / spriteSheetDimensions.y);
      }
    }
  }
}