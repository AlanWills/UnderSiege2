#include "stdafx.h"

#include "UI/TurretGUIManager.h"
#include "UI/TurretGUI.h"
#include "UI/StackPanel.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Resources/ResourceManager.h"
#include "Turrets/Turret.h"

using namespace CelesteEngine::Resources;


namespace US
{
  namespace UI
  {
    REGISTER_SCRIPTABLE_OBJECT(TurretGUIManager)

    //------------------------------------------------------------------------------------------------
    TurretGUIManager::TurretGUIManager() :
      m_gameObject()
    {
    }

    //------------------------------------------------------------------------------------------------
    void TurretGUIManager::setup(const Handle<GameObject>& gameObject, const std::vector<Turret*>& turrets)
    {
      m_gameObject = gameObject;

      const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(Path("Prefabs", "UI", "TurretGUI.prefab"));
      if (prefab.is_null())
      {
        ASSERT_FAIL();
        return;
      }

      const Handle<CelesteEngine::UI::StackPanel>& stackPanel = m_gameObject->findComponent<CelesteEngine::UI::StackPanel>();

      for (const Turret* turret : turrets)
      {
        const Handle<GameObject>& turretGameObject = prefab->instantiate(m_gameObject->getOwnerScreen());
        turretGameObject->setParent(m_gameObject);

        TurretGUI* turretGUI = ScriptableObject::create<TurretGUI>(turret->getName() + "GUI");
        turretGUI->setup(turretGameObject, turret);

        stackPanel->addChildren(turretGameObject);
      }
    }
  }
}