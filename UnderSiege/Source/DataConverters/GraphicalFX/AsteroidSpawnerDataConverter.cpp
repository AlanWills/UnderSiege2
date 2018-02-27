#include "stdafx.h"

#include "DataConverters/GraphicalFX/AsteroidSpawnerDataConverter.h"


namespace US
{
  REGISTER_COMPONENT_DATA_CONVERTER(AsteroidSpawnerDataConverter)

  //------------------------------------------------------------------------------------------------
  AsteroidSpawnerDataConverter::AsteroidSpawnerDataConverter(const ElementName& elementName) :
    Inherited(elementName),
    m_asteroids(ElementName("Asteroids"), ChildElementName("Asteroid"), kRequired)
  {
    addElement(&m_asteroids);
  }

  //------------------------------------------------------------------------------------------------
  void AsteroidSpawnerDataConverter::doSetValues(const Handle<AsteroidSpawner>& asteroidSpawner) const
  {
    ASSERT(!m_asteroids.getChildren().empty());

    // Spawn asteroids
    for (const AsteroidSpawnerElementDataConverter& asteroidElement : m_asteroids)
    {
      asteroidSpawner->spawn(asteroidElement.getPrefabPath(), asteroidElement.getCount());
    }
  }
}