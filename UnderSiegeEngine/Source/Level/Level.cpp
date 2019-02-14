#include "stdafx.h"

#include "Level/Level.h"
#include "Screens/Loading/ScreenLoader.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "TileMap/TileMap.h"


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Level)
  
  //------------------------------------------------------------------------------------------------
  Level::Level() :
    Inherited(),
    m_screenPath(createReferenceField<Path>("screen_path")),
    m_tileMapPath(createReferenceField<Path>("tile_map_path"))
  {
  }

  //------------------------------------------------------------------------------------------------
  Handle<Screen> Level::initialize()
  {
    Handle<Screen> screen = ScreenLoader::load(getScreenPath());
    ASSERT(!screen.is_null());

    TileMap* tileMap = ScriptableObject::load<TileMap>(m_tileMapPath->getValue());
    ASSERT(tileMap != nullptr);

    tileMap->instantiate(screen->findGameObjectWithName("TileMap"));

    return screen;
  }
}