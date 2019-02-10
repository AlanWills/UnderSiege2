#include "stdafx.h"

#include "Level/Level.h"
#include "Screens/Loading/ScreenLoader.h"
#include "Registries/ScriptableObjectRegistry.h"


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Level)
  
  //------------------------------------------------------------------------------------------------
  Level::Level() :
    Inherited(),
    m_screenPath(createReferenceField<Path>("screen")),
    m_tileMapPath(createReferenceField<Path>("tile_map"))
  {
  }

  //------------------------------------------------------------------------------------------------
  Handle<Screen> Level::initialize()
  {
    Handle<Screen> screen = ScreenLoader::load(getScreenPath());
    ASSERT(!screen.is_null());

    return screen;
  }
}