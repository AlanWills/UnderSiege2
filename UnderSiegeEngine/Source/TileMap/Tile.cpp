#include "stdafx.h"

#include "TileMap/Tile.h"
#include "Registries/ScriptableObjectRegistry.h"


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Tile)

  //------------------------------------------------------------------------------------------------
  Tile::Tile() :
    m_texture(createHandleField<CelesteEngine::Resources::Texture2D>("texture")),
    m_traversable(createValueField<bool>("traversable")),
    m_position()
  {
  }
}