#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/ScriptableObject.h"
#include "Serialization/MathsSerializers.h"
#include "Tile.h"


namespace US
{
  class UnderSiegeEngineDllExport TileMap : public CelesteEngine::ScriptableObject
  {
    DECLARE_SCRIPTABLE_OBJECT(TileMap)

    public:
      void instantiate(const Handle<GameObject>& parentGameObject) const;

      const Path& getTilePrefab() const { return m_tilePrefab->getValue(); }
      const glm::uvec2& getTileDimensions() const { return m_tileDimensions->getValue(); }

    protected:
      bool doDeserialize(const tinyxml2::XMLElement* element) override;

    private:
      using Inherited = CelesteEngine::ScriptableObject;

      ReferenceField<Path>* m_tilePrefab;
      ReferenceField<glm::uvec2>* m_tileDimensions;
      std::vector<Tile*> m_tiles;
  };
}