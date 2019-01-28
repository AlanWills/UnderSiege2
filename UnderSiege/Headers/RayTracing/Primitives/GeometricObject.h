#pragma once

#include "RayTracing/Ray.h"
#include "RayTracing/ShadeRec.h"


class GeometricObject
{
  public:
    GeometricObject(const RGBColor& colour);
    virtual ~GeometricObject();

    const RGBColor& getColour() const { return m_colour; }
    void setColour(const RGBColor& colour) { m_colour = colour; }

    virtual bool hit(const Ray& rau, double& tmin, ShadeRec& shadeRec) const = 0;

  private:
    RGBColor m_colour;
};