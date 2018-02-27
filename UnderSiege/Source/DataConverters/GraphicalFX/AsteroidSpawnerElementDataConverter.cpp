#include "stdafx.h"

#include "DataConverters/GraphicalFX/AsteroidSpawnerElementDataConverter.h"


namespace US
{
  //------------------------------------------------------------------------------------------------
  AsteroidSpawnerElementDataConverter::AsteroidSpawnerElementDataConverter(const ElementName& elementName) :
    Inherited(elementName),
    m_prefabPath(),
    m_count(AttributeName("count"), 0, kRequired)
  {
    addAttribute(&m_count);
  }

  //------------------------------------------------------------------------------------------------
  bool AsteroidSpawnerElementDataConverter::doConvertFromXML(const XMLElement* element)
  {
    const char* elementText = element->GetText();
    if (elementText == nullptr)
    {
      ASSERT_FAIL();
      return false;
    }

    m_prefabPath.assign(elementText);
    return Inherited::doConvertFromXML(element);
  }
}