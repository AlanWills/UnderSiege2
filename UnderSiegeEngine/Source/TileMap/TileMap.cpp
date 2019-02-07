#include "stdafx.h"

#include "TileMap/TileMap.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Deserialization/MathsDeserializers.h"


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(TileMap)

  //------------------------------------------------------------------------------------------------
  TileMap::TileMap() :
    m_dimensions(createReferenceField<glm::vec2>("dimensions")),
    m_tiles()
  {
  }

  //------------------------------------------------------------------------------------------------
  bool TileMap::doDeserialize(const tinyxml2::XMLElement* element)
  {
    if (!Inherited::doDeserialize(element))
    {
      ASSERT_FAIL();
      return false;
    }

    const tinyxml2::XMLElement* tileElements = element->FirstChildElement("Tiles");
    bool deserializedCorrectly = tileElements != nullptr;
    ASSERT(deserializedCorrectly);

    if (tileElements != nullptr)
    {
      for (auto tileElement : XML::children(tileElements))
      {
        const char* elementText = tileElement->GetText();
        if (elementText != nullptr)
        {
          // Change this to use flyweight - only load in one copy of each unique tile
          Tile* tile = ScriptableObject::load<Tile>(elementText);
          if (tile != nullptr)
          {
            const tinyxml2::XMLAttribute* attribute = tileElement->FindAttribute("position");
            deserializedCorrectly &= attribute != nullptr;
            ASSERT(deserializedCorrectly);

            if (attribute != nullptr)
            {
              glm::ivec2 position;
              CelesteEngine::deserialize<glm::ivec2>(attribute->Value(), position);
              tile->setPosition(position);

              m_tiles.push_back(tile);
            }
          }
        }
      }
    }

    return deserializedCorrectly;
  }
}