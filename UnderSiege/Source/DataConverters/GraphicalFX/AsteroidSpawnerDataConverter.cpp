#include "stdafx.h"

#include "DataConverters/GraphicalFX/AsteroidSpawnerDataConverter.h"
#include "Registries/ComponentDataConverterRegistry.h"


namespace US
{
  REGISTER_COMPONENT_DATA_CONVERTER(AsteroidSpawnerDataConverter)

  //------------------------------------------------------------------------------------------------
  AsteroidSpawnerDataConverter::AsteroidSpawnerDataConverter(const std::string& elementName) :
    Inherited(elementName),
    m_asteroids()
  {
  }

  //------------------------------------------------------------------------------------------------
  AsteroidSpawnerDataConverter::~AsteroidSpawnerDataConverter()
  {
    for (const AsteroidDataConverter* converter : m_asteroids)
    {
      delete converter;
    }
  }

  //------------------------------------------------------------------------------------------------
  bool AsteroidSpawnerDataConverter::doConvertFromXML(const XMLElement* objectElement)
  {
    bool result = Inherited::doConvertFromXML(objectElement);

    for (const XMLElement* element : children(objectElement, getAsteroidXMLName()))
    {
      AsteroidDataConverter* converter = new AsteroidDataConverter(element->Name());
      if (!converter->convertFromXML(element))
      {
        ASSERT_FAIL();
        return false;
      }

      m_asteroids.push_back(converter);
    }

    return result;
  }

  //------------------------------------------------------------------------------------------------
  void AsteroidSpawnerDataConverter::doSetValues(const Handle<AsteroidSpawner>& asteroidSpawner) const
  {
    ASSERT(!m_asteroids.empty());

    // Spawn asteroids
    for (const AsteroidDataConverter* asteroidElement : m_asteroids)
    {
      asteroidSpawner->spawn(asteroidElement->getPrefabPath(), asteroidElement->getCount());
    }
  }
}