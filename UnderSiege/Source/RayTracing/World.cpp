#include "RayTracing/World.h"
#include "RayTracing/Constants.h"
#include "RayTracing/ColourTracer.h"
#include "Debugging/Debug.h"

#include <fstream>

// -------------------------------------------------------------------- default constructor

// tracer_ptr is set to NULL because the build functions will always construct the appropriate tracer
// ambient_ptr is set to a default ambient light because this will do for most scenes
// camera_ptr is set to NULL because the build functions will always have to construct a camera
// and set its parameters

World::World(int width, int height) :
  background_color(black),
	tracer_ptr(nullptr),
  m_objects()
{
  vp.set_hres(width);
  vp.set_vres(height);
}

//------------------------------------------------------------------ render_scene
void World::build()
{
  vp.set_pixel_size(1.0f);
  vp.set_gamma(1.0f);

  background_color = black;
  tracer_ptr.reset(new ColourTracer(this));
}

//------------------------------------------------------------------ render_scene

// This uses orthographic viewing along the zw axis

//------------------------------------------------------------------------------------------------
void World::renderLine(int line, const Handle<CelesteEngine::Resources::Texture2D>& texture) const
{
  RGBColor	pixel_color;
  US::RayTracing::Ray			ray;
  int 		hres = vp.hres;
  int 		vres = vp.vres;
  float		s = vp.s;
  float		zw = 100.0;				// hardwired in

  ray.setDirection(Vector3D(0, 0, -1));

  std::unique_ptr<unsigned char> data(new unsigned char[4]);

  for (int c = 0; c < hres; c++)
  {
    float r = 0;
    float g = 0;
    float b = 0;

    // Current pixel
    {
      ray.setOrigin(Point3D(s * (c - hres / 2.0 + 0.5), s * (line - vres / 2.0 + 0.5), zw));
      pixel_color = tracer_ptr->trace_ray(ray);

      r += pixel_color.r;
      g += pixel_color.g;
      b += pixel_color.b;
    }

    // Pixel to left
    {
      ray.setOrigin(Point3D(s * ((c - 1) - hres / 2.0 + 0.5), s * (line - vres / 2.0 + 0.5), zw));
      pixel_color = tracer_ptr->trace_ray(ray);

      r += pixel_color.r;
      g += pixel_color.g;
      b += pixel_color.b;
    }

    // Pixel to right
    {
      ray.setOrigin(Point3D(s * ((c + 1) - hres / 2.0 + 0.5), s * (line - vres / 2.0 + 0.5), zw));
      pixel_color = tracer_ptr->trace_ray(ray);

      r += pixel_color.r;
      g += pixel_color.g;
      b += pixel_color.b;
    }

    // Pixel above
    {
      ray.setOrigin(Point3D(s * ((c - 1) - hres / 2.0 + 0.5), s * ((line + 1) - vres / 2.0 + 0.5), zw));
      pixel_color = tracer_ptr->trace_ray(ray);

      r += pixel_color.r;
      g += pixel_color.g;
      b += pixel_color.b;
    }

    // Pixel below
    {
      ray.setOrigin(Point3D(s * ((c - 1) - hres / 2.0 + 0.5), s * ((line - 1) - vres / 2.0 + 0.5), zw));
      pixel_color = tracer_ptr->trace_ray(ray);

      r += pixel_color.r;
      g += pixel_color.g;
      b += pixel_color.b;
    }

    // Average
    const int numSamples = 5;
    r /= numSamples;
    g /= numSamples;
    b /= numSamples;

    data.get()[0] = static_cast<unsigned char>(r * 255);
    data.get()[1] = static_cast<unsigned char>(g * 255);
    data.get()[2] = static_cast<unsigned char>(b * 255);
    data.get()[3] = 255;

    texture->setPixel(c, line, data.get());
  }
}

void 												
World::render_scene(const Handle<CelesteEngine::Resources::Texture2D>& texture) const 
{
  // Use this when we have non-blocking texture updating

	RGBColor	pixel_color;	 	
  US::RayTracing::Ray			ray;
	int 		hres 	= vp.hres;
	int 		vres 	= vp.vres;
	float		s		= vp.s;
	float		zw		= 100.0;				// hardwired in

	ray.setDirection(Vector3D(0, 0, -1));
	
  std::unique_ptr<unsigned char> data(new unsigned char[4]);
  for (int r = 0; r < vres; r++)			// up
  {
    for (int c = 0; c < hres; c++) 
    {	// across 					
      ray.setOrigin(Point3D(s * (c - hres / 2.0 + 0.5), s * (r - vres / 2.0 + 0.5), zw));
      pixel_color = tracer_ptr->trace_ray(ray);
      
      data.get()[0] = static_cast<unsigned char>(pixel_color.r * 255);
      data.get()[1] = static_cast<unsigned char>(pixel_color.g * 255);
      data.get()[2] = static_cast<unsigned char>(pixel_color.b * 255);
      data.get()[3] = 255;

      texture->setPixel(c, r, data.get());
    }
  }
}

//------------------------------------------------------------------------------------------------
void World::addObject(GeometricObject* object)
{
  m_objects.push_back(std::shared_ptr<GeometricObject>(object));
}