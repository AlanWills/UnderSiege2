#include "stdafx.h"

#include "RayTracing/RayTracer.h"
#include "Objects/GameObject.h"
#include "Input/InputUtils.h"
#include "Rendering/SpriteRenderer.h"
#include "RayTracing/World.h"

using Texture2D = CelesteEngine::Resources::Texture2D;


namespace US
{
  namespace RayTracing
  {
    REGISTER_SCRIPT(RayTracer, 1)

    //------------------------------------------------------------------------------------------------
    RayTracer::RayTracer() :
      m_texture(PinnedHandle<Texture2D>::make_pinned())
    {
    }

    //------------------------------------------------------------------------------------------------
    RayTracer::~RayTracer()
    {
    }

    //------------------------------------------------------------------------------------------------
    void RayTracer::onHandleInput()
    {
      Inherited::onHandleInput();

      if (Input::isKeyPressed(GLFW_KEY_R))
      {
        raycast();
      }
    }

    //------------------------------------------------------------------------------------------------
    void RayTracer::onDeath()
    {
      Inherited::onDeath();

      m_texture->unload();
    }

    //------------------------------------------------------------------------------------------------
    void RayTracer::raycast()
    {
      World world;
      world.build();

      std::vector<float> worldData(world.vp.hres * world.vp.vres * 3);
      world.render_scene(worldData);

      std::vector<unsigned char> textureImgData(world.vp.hres * world.vp.vres * 4);
      for (int y = 0, yMax = world.vp.vres; y < yMax; ++y)
      {
        for (int x = 0, xMax = world.vp.hres; x < xMax; ++x)
        {
          textureImgData[y * xMax * 4 + x * 4] = worldData[y * xMax * 3 + x * 3] * 255;
          textureImgData[y * xMax * 4 + x * 4 + 1] = worldData[y * xMax * 3 + x * 3 + 1] * 255;
          textureImgData[y * xMax * 4 + x * 4 + 2] = worldData[y * xMax * 3 + x * 3 + 2] * 255;
          textureImgData[y * xMax * 4 + x * 4 + 3] = 255;
        }
      }

      m_texture->unload();
      m_texture->generate(world.vp.hres, world.vp.vres, textureImgData.data());

      getGameObject()->findComponent<Rendering::SpriteRenderer>()->setTexture(m_texture.handle());
      getGameObject()->findComponent<Rendering::SpriteRenderer>()->setDimensions(m_texture->getDimensions());
    }
  }
}