#pragma once

#include "glm/glm.hpp"


namespace US
{
  namespace RayTracing
  {
    class Ray
    {
      public:
        Ray();
        Ray(const glm::vec3& origin, const glm::vec3& direction);

        const glm::vec3& getOrigin() const { return m_origin; }
        void setOrigin(const glm::vec3& origin) { m_origin = origin; }

        const glm::vec3& getDirection() const { return m_direction; }
        void setDirection(const glm::vec3& direction) { m_direction = direction; }

      private:
        glm::vec3 m_origin;
        glm::vec3 m_direction;
    };
  }
}