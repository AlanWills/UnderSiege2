#pragma once

#include "RayTracing/ViewPlane.h"
#include "RayTracing/RGBColor.h"
#include "RayTracing/Tracer.h"
#include "RayTracing/Primitives/Sphere.h"

#include <vector>
#include <memory>


class World 
{	
  private:
    using WorldObjects = std::vector<std::shared_ptr<GeometricObject>>;

	public:
		ViewPlane					vp;
		RGBColor					background_color;
		std::unique_ptr<Tracer>	tracer_ptr;

		World(int width, int height);												
		
    void addObject(GeometricObject* object);
		void build();
		void render_scene(std::vector<float>& imgdata) const;

    WorldObjects::const_iterator begin() const { return m_objects.cbegin(); }
    WorldObjects::const_iterator end() const { return m_objects.cend(); }
			
  private:
    WorldObjects m_objects;
};