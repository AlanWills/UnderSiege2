#include "stdafx.h"

#include "Callbacks/LoadLevelCallback.h"
#include "Registries/CallbackRegistry.h"
#include "Objects/GameObject.h"
#include "Screens/Screen.h"
#include "Level/Level.h"
#include "Resources/ResourceManager.h"


namespace US
{
  REGISTER_CALLBACK(LoadLevel)

  //------------------------------------------------------------------------------------------------
  void LoadLevel::operator()(const Handle<GameObject>& gameObject, const std::string& arg)
  {
    if (gameObject.is_null() ||
        gameObject->getOwnerScreen().is_null() ||
        arg.empty())
    {
      ASSERT_FAIL();
      return;
    }

    Path levelFile(Resources::getResourcesDirectory(), arg);
    if (!File::exists(levelFile))
    {
      ASSERT_FAIL();
      return;
    }

    Level* level = ScriptableObject::load<Level>(levelFile);
    //level->makeCurrent();
  }
}