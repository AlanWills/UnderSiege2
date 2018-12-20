#include "stdafx.h"

#include "Turrets/Turret.h"
#include "Registries/ScriptableObjectRegistry.h"
#include "Objects/GameObject.h"
#include "Turrets/TurretController.h"
#include "Animation/Animation.h"
#include "Bullets/Bullet.h"

using namespace CelesteEngine::Resources;


namespace US
{
  REGISTER_SCRIPTABLE_OBJECT(Turret)

  //------------------------------------------------------------------------------------------------
  Turret::Turret() :
    m_damage(createValueField<int>("damage", 0)),
    m_fireRate(createValueField<float>("fire_rate", 1)),
    m_bulletAsset(createReferenceField<Path>("bullet")),
    m_turretPrefab(createReferenceField<Path>("turret_prefab")),
    m_firingAnimationFrames()
  {
  }

  //------------------------------------------------------------------------------------------------
  bool Turret::doDeserialize(const tinyxml2::XMLElement* element)
  {
    const tinyxml2::XMLElement* animationFrames = element->FirstChildElement("AnimationFrames");
    if (animationFrames == nullptr)
    {
      // This is an error - no sprite images provided for turret
      ASSERT_FAIL();
      return false;
    }

    for (auto child : XML::children(animationFrames))
    {
      const char* framePath = child->GetText();
      if (framePath != nullptr)
      {
        const Handle<Texture2D>& animationFrame = getResourceManager()->load<Texture2D>(framePath);
        ASSERT(!animationFrame.is_null());

        if (!animationFrame.is_null())
        {
          m_firingAnimationFrames.push_back(animationFrame);
        }
      }
    }

    m_bullet = ScriptableObject::load<Bullet>(m_bulletAsset->getValue());
    if (m_bullet == nullptr)
    {
      ASSERT_FAIL();
      return false;
    }

    m_bullet->setTurret(this);

    return true;
  }

  //------------------------------------------------------------------------------------------------
  Handle<GameObject> Turret::create(const Handle<Screen>& screen) const
  {
    const Handle<Prefab>& prefab = getResourceManager()->load<Prefab>(m_turretPrefab->getValue());
    if (prefab.is_null())
    {
      ASSERT_FAIL();
      return Handle<GameObject>();
    }

    Handle<GameObject> gameObject = prefab->instantiate(screen);
    gameObject->findComponent<TurretController>()->setTurret(this);
    gameObject->findComponent<Animation>()->addFrames(m_firingAnimationFrames);
    gameObject->findComponent<SpriteRenderer>()->setTexture(m_firingAnimationFrames[0]);

    return gameObject;
  }
}