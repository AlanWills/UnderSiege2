#pragma once

#include "GeometricObject.h"


class Plane : public GeometricObject
{
  public:
    Plane(const RGBColor& colour);
    Plane(const Point3D& point, const Normal& normal, const RGBColor& colour);

    bool hit(const US::RayTracing::Ray& ray, double& tMin, ShadeRec& shadeRect) const override;

  private:
    using Inherited = GeometricObject;

    static const double s_epsilon;

    Point3D m_point;
    Normal m_normal;
};