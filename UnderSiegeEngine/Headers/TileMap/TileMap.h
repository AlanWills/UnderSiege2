#pragma once

#include "Objects/ScriptableObject.h"
#include "Tile.h"
#include "UnderSiegeEngineDllExport.h"


namespace US
{
  class UnderSiegeEngineDllExport TileMap : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(TileMap)

    protected:
      bool doDeserialize(const tinyxml2::XMLElement* element) override;

    private:
      using Inherited = CelesteEngine::ScriptableObject;

      ReferenceField<glm::vec2>* m_dimensions;
      std::vector<Tile*> m_tiles;
  };
}