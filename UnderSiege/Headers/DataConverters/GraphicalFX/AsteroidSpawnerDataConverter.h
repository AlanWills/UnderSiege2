#pragma once

#include "DataConverters/Objects/ComponentDataConverter.h"
#include "GraphicalFX/AsteroidSpawner.h"
#include "XML/Elements/ListElement.h"
#include "DataConverters/GraphicalFX/AsteroidSpawnerElementDataConverter.h"


namespace US
{

class AsteroidSpawnerDataConverter : public CelesteEngine::ComponentDataConverter
{
  DECLARE_COMPONENT_DATA_CONVERTER(AsteroidSpawner)

  public:
    AsteroidSpawnerDataConverter(const ElementName& elementName = AsteroidSpawner::name());

    const std::vector<AsteroidSpawnerElementDataConverter>& getAsteroids() const { return m_asteroids.getChildren(); }
    const std::string& getAsteroidsXMLName() const { return m_asteroids.getElementName(); }
    const std::string& getAsteroidXMLName() const { return m_asteroids.getChildElementName(); }

  private:
    typedef CelesteEngine::ComponentDataConverter Inherited;

    ListElement<AsteroidSpawnerElementDataConverter> m_asteroids;
};

}