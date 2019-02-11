#pragma once

#include "Objects/ScriptableObject.h"
#include "UnderSiegeEngineDllExport.h"


namespace US
{
  class UnderSiegeEngineDllExport Tile : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(Tile)

    public:
      const glm::uvec2& getPosition() const { return m_position; }
      void setPosition(const glm::uvec2& position) { m_position = position; }

      const Handle<CelesteEngine::Resources::Texture2D>& getTexture() const { return m_texture->getValue(); }
      bool getTraversable() const { return m_traversable->getValue(); }

    private:
      using Inherited = CelesteEngine::ScriptableObject;

      HandleField<CelesteEngine::Resources::Texture2D>* m_texture;
      ValueField<bool>* m_traversable;
      
      glm::uvec2 m_position;
  };
}