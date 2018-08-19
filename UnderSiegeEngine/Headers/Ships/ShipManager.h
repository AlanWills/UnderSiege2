#pragma once

#include "UnderSiegeEngineDllExport.h"
#include "Objects/ScriptableObject.h"
#include "Ship.h"


namespace US
{

class UnderSiegeEngineDllExport ShipManager : public ScriptableObject
{
  DECLARE_SCRIPTABLE_OBJECT(ShipManager)

  public:
    ShipManager() { }

  private:

};

}