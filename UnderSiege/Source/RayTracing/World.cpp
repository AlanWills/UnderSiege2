#include "RayTracing/World.h"
#include "RayTracing/Constants.h"
#include "RayTracing/SingleSphere.h"
#include "Debugging/Debug.h"

#include <fstream>

struct lwrite
{
  unsigned long value;
  unsigned      size;
  lwrite(unsigned long value, unsigned size) :
    value(value), size(size)
  { }
};

//--------------------------------------------------------------------------
inline std::ostream& operator << (std::ostream& outs, const lwrite& v)
{
  unsigned long value = v.value;
  for (unsigned cntr = 0; cntr < v.size; cntr++, value >>= 8)
    outs.put(static_cast <char> (value & 0xFF));
  return outs;
}

// -------------------------------------------------------------------- default constructor

// tracer_ptr is set to NULL because the build functions will always construct the appropriate tracer
// ambient_ptr is set to a default ambient light because this will do for most scenes
// camera_ptr is set to NULL because the build functions will always have to construct a camera
// and set its parameters

World::World(void) :
  background_color(black),
	tracer_ptr(nullptr)
{
}

//------------------------------------------------------------------ render_scene
void World::build()
{
  vp.set_hres(200);
  vp.set_vres(200);
  vp.set_pixel_size(1.0f);
  vp.set_gamma(1.0f);

  background_color = black;
  tracer_ptr.reset(new SingleSphere(this));

  sphere.setCentre(0);
  sphere.setRadius(85);
}

//------------------------------------------------------------------ render_scene

// This uses orthographic viewing along the zw axis

void 												
World::render_scene(std::vector<float>& imgdata) const {

	RGBColor	pixel_color;	 	
	Ray			ray;					
	int 		hres 	= vp.hres;
	int 		vres 	= vp.vres;
	float		s		= vp.s;
	float		zw		= 100.0;				// hardwired in

	ray.setDirection(Vector3D(0, 0, -1));
	
  for (int r = 0; r < vres; r++)			// up
  {
    for (int c = 0; c < hres; c++) 
    {	// across 					
      ray.setOrigin(Point3D(s * (c - hres / 2.0 + 0.5), s * (r - vres / 2.0 + 0.5), zw));
      pixel_color = tracer_ptr->trace_ray(ray);
      
      imgdata[r * vres * 3 + c * 3 + 0] = pixel_color.r;
      imgdata[r * vres * 3 + c * 3 + 1] = pixel_color.g;
      imgdata[r * vres * 3 + c * 3 + 2] = pixel_color.b;
    }
  }
}