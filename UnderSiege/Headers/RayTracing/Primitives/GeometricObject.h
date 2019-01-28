#pragma once

#include "RayTracing/Ray.h"
#include "RayTracing/ShadeRec.h"


class GeometricObject
{
  public:
    virtual bool hit(const Ray& rau, double& tmin, ShadeRec& shadeRec) const = 0;
};