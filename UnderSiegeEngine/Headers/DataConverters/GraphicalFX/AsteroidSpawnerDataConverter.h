#pragma once

#include "DataConverters/Objects/ComponentDataConverter.h"
#include "GraphicalFX/AsteroidSpawner.h"
#include "XML/Elements/DataConverterListElement.h"
#include "DataConverters/GraphicalFX/AsteroidDataConverter.h"


namespace US
{

class AsteroidSpawnerDataConverter : public CelesteEngine::ComponentDataConverter
{
  DECLARE_COMPONENT_DATA_CONVERTER(AsteroidSpawnerDataConverter, AsteroidSpawner)

  public:
    ~AsteroidSpawnerDataConverter();

    const std::vector<AsteroidDataConverter*>& getAsteroids() const { return m_asteroids; }
    std::string getAsteroidXMLName() const { return "Asteroid"; }

  protected:
    bool doConvertFromXML(const XMLElement* objectElement) override;

  private:
    typedef CelesteEngine::ComponentDataConverter Inherited;

    std::vector<AsteroidDataConverter*> m_asteroids;
};

}