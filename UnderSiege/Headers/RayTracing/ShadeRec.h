#pragma once

#include "glm/glm.hpp"
#include "Ray.h"

#include <vector>


namespace US
{
  namespace RayTracing
  {
    class Material;
    class World;

    class ShadeRec 
    {
      public:
        bool				hit_an_object;		// Did the ray hit an object?
        Material* 			material_ptr;		// Pointer to the nearest object's material
        glm::vec3 			hit_point;			// World coordinates of intersection
        glm::vec3				local_hit_point;	// World coordinates of hit point on generic object (used for texture transformations)
        glm::vec3				normal;				// Normal at hit point
        Ray					ray;				// Required for specular highlights and area lights
        int					depth;				// recursion depth
        float				t;					// ray parameter
        World&				w;					// World reference
        glm::vec3            color;

        ShadeRec(World& wr);					// constructor
    };
  }
}