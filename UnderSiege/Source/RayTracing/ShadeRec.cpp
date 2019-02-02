#include "stdafx.h"

#include "RayTracing/Constants.h"
#include "RayTracing/ShadeRec.h"
#include "RayTracing/World.h"


namespace US
{
  namespace RayTracing
  {
    //------------------------------------------------------------------------------------------------
    ShadeRec::ShadeRec(World& wr) :
      hit_an_object(false),
      material_ptr(NULL),
      hit_point(),
      local_hit_point(),
      normal(),
      ray(),
      depth(0),
      t(0.0),
      w(wr),
      color(wr.background_color)
    {
    }
  }
}