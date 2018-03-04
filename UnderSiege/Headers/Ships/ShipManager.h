#pragma once

#include "Objects/ScriptableObject.h"
#include "Ship.h"


namespace US
{

class ShipManager : public ScriptableObject
{
  DECLARE_SCRIPTABLE_OBJECT(ShipManager)

  public:
    ShipManager() { }

  private:

};

}