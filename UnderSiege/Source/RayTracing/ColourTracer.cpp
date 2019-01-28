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
RGBColor ColourTracer::trace_ray(const Ray& ray) const 
{
	ShadeRec	sr(*world_ptr); 	// not used
	double    	t;  				// not used
	
  for (const auto& object : *world_ptr)
  {
    if (object->hit(ray, t, sr))
    {
      return object->getColour();
    }
  }
	 
  return world_ptr->background_color;
}


