#include "stdafx.h"

#include "DataConverters/GraphicalFX/AsteroidDataConverter.h"


namespace US
{
  //------------------------------------------------------------------------------------------------
  AsteroidDataConverter::AsteroidDataConverter(const std::string& elementName) :
    Inherited(elementName),
    m_prefabPath(),
    m_count("count", 0, DeserializationRequirement::kRequired)
  {
    addData(&m_count);
  }

  //------------------------------------------------------------------------------------------------
  bool AsteroidDataConverter::doConvertFromXML(const XMLElement* element)
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