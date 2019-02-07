#pragma once

#include "Objects/ScriptableObject.h"
#include "UnderSiegeEngineDllExport.h"


namespace US
{
  class UnderSiegeEngineDllExport Tile : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(Tile)

    public:
      const glm::ivec2& getPosition() const { return m_position; }
      void setPosition(const glm::ivec2& position) { m_position = position; }

      const std::string& getSprite() const { return m_sprite->getValue(); }
      bool getTraversable() const { return m_traversable->getValue(); }

    private:
      using Inherited = CelesteEngine::ScriptableObject;

      ReferenceField<std::string>* m_sprite;
      ValueField<bool>* m_traversable;
      
      glm::ivec2 m_position;
  };
}