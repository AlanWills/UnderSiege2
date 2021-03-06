#pragma once

#include "RayTracing/ViewPlane.h"
#include "RayTracing/Tracer.h"
#include "Primitives/Primitive.h"
#include "Resources/2D/Texture2D.h"

#include <vector>
#include <memory>


namespace US
{
  namespace RayTracing
  {
    class World
    {
      private:
        using WorldObjects = std::vector<std::shared_ptr<Primitive>>;

      public:
        ViewPlane	vp;
        glm::vec3	background_color;
        std::unique_ptr<Tracer>	tracer_ptr;

        World(int width, int height);

        float getRayZPosition() const { return m_rayZPosition; }
        void setRayZPosition(float rayZPosition) { m_rayZPosition = rayZPosition; }

        void addObject(Primitive* object);
        void build();
        void renderLine(int line, const Handle<CelesteEngine::Resources::Texture2D>& texture) const;
        void render_scene(const Handle<CelesteEngine::Resources::Texture2D>& texture) const;

        WorldObjects::const_iterator begin() const { return m_objects.cbegin(); }
        WorldObjects::const_iterator end() const { return m_objects.cend(); }

      private:
        WorldObjects m_objects;

        float m_rayZPosition;
    };
  }
}