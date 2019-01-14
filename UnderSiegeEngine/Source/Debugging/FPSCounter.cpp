#include "stdafx.h"

#include "Debugging/FPSCounter.h"
#include "Rendering/TextRenderer.h"
#include "Objects/GameObject.h"


namespace US
{
  namespace Debugging
  {
    REGISTER_SCRIPT(FPSCounter, 1)

    //------------------------------------------------------------------------------------------------
    FPSCounter::FPSCounter() :
      m_textRenderer(),
      m_current(0)
    {
    }

    //------------------------------------------------------------------------------------------------
    FPSCounter::~FPSCounter()
    {
    }

    //------------------------------------------------------------------------------------------------
    void FPSCounter::onSetGameObject(const Handle<GameObject>& gameObject)
    {
      Inherited::onSetGameObject(gameObject);

      m_textRenderer = gameObject->findComponent<CelesteEngine::Rendering::TextRenderer>();
      ASSERT(!m_textRenderer.is_null());
    }

    //------------------------------------------------------------------------------------------------
    void FPSCounter::onUpdate(float elapsedGameTime)
    {
      Inherited::onUpdate(elapsedGameTime);

      m_current += elapsedGameTime;

      if (m_current > 0.5f)
      {
        size_t fps = static_cast<size_t>(1 / elapsedGameTime);
        m_textRenderer->setLine(0, std::to_string(fps));
        m_current = 0;
      }
    }
  }
}