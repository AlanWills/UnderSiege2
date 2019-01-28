#include "RayTracing/ColourTracer.h"
#include "RayTracing/World.h"
#include "RayTracing/ShadeRec.h"


// --------------------------------------------------------------------
		
ColourTracer::ColourTracer(World* _worldPtr) :
  Tracer(_worldPtr)
{
}


// --------------------------------------------------------------------
ColourTracer::~ColourTracer() 
{
}


// --------------------------------------------------------------------
RGBColor ColourTracer::trace_ray(const US::RayTracing::Ray& ray) const
{
	ShadeRec	sr(*world_ptr); 	// not used
	double t = std::numeric_limits<double>::max();  				// not used
	
  for (const auto& object : *world_ptr)
  {
    object->hit(ray, t, sr);
  }
	 
  return sr.color;
}


