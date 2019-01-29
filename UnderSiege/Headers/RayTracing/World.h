#pragma once

#include "RayTracing/ViewPlane.h"
#include "RayTracing/RGBColor.h"
#include "RayTracing/Tracer.h"
#include "Primitives/GeometricObject.h"
#include "Resources/2D/Texture2D.h"

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
    void renderLine(int line, const Handle<CelesteEngine::Resources::Texture2D>& texture) const;
    void render_scene(const Handle<CelesteEngine::Resources::Texture2D>& texture) const;

    WorldObjects::const_iterator begin() const { return m_objects.cbegin(); }
    WorldObjects::const_iterator end() const { return m_objects.cend(); }
			
  private:
    WorldObjects m_objects;
};