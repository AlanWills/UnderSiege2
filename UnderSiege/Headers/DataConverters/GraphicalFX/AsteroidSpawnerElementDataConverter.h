#pragma once

#include "DataConverters/DataConverter.h"
#include "XML/Attributes/DataAttribute.h"
#include "XML/Elements/StringElement.h"


namespace US
{

class AsteroidSpawnerElementDataConverter : public CelesteEngine::DataConverter
{
  public:
    AsteroidSpawnerElementDataConverter(const ElementName& elementName = ElementName("AsteroidSpawner"));

    const std::string& getPrefabPath() const { return m_prefabPath; }

    size_t getCount() const { return m_count.getValue(); }
    const std::string& getCountXMLName() const { return m_count.getAttributeName(); }

  protected:
    bool doConvertFromXML(const XMLElement* objectElement) override;

  private:
    typedef CelesteEngine::DataConverter Inherited;

    std::string m_prefabPath;
    ValueAttribute<size_t> m_count;
};

}