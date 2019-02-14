#include "stdafx.h"

#include "TileMap/TileMap.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Deserialization/MathsDeserializers.h"
#include "Rendering/SpriteRenderer.h"


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(TileMap)

  //------------------------------------------------------------------------------------------------
  TileMap::TileMap() :
    m_tilePrefab(createReferenceField<Path>("tile_prefab_path")),
    m_tileDimensions(createReferenceField<glm::uvec2>("tile_dimensions")),
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
              glm::uvec2 position;
              CelesteEngine::deserialize<glm::uvec2>(attribute->Value(), position);
              tile->setPosition(position);

              m_tiles.push_back(tile);
            }
          }
        }
      }
    }

    return deserializedCorrectly;
  }

  //------------------------------------------------------------------------------------------------
  void TileMap::instantiate(const Handle<GameObject>& parentGameObject) const
  {
    const Handle<Resources::Prefab>& prefab = Resources::getResourceManager()->load<Resources::Prefab>(getTilePrefab());
    ASSERT(!prefab.is_null());

    for (const auto& tile : m_tiles)
    {
      // Create a new tile from the prefab
      const Handle<GameObject>& tileGameObject = prefab->instantiate(parentGameObject->getOwnerScreen());

      // Set up transform hierarcy, position and dimensions
      tileGameObject->setParent(parentGameObject);
      tileGameObject->getTransform()->setTranslation(tile->getPosition() * getTileDimensions());
      tileGameObject->findComponent<Rendering::SpriteRenderer>()->setDimensions(getTileDimensions());

      // Then populate with tile data
      tile->instantiate(tileGameObject);
    }
  }
}