#include "stdafx.h"

#include "RayTracing/RayTracer.h"
#include "Objects/GameObject.h"
#include "Input/InputUtils.h"
#include "Rendering/SpriteRenderer.h"
#include "Lua/LuaState.h"
#include "Resources/ResourceManager.h"

using namespace CelesteEngine;
using Texture2D = CelesteEngine::Resources::Texture2D;


namespace US
{
  namespace RayTracing
  {
    REGISTER_SCRIPT(RayTracer, 1)

    //------------------------------------------------------------------------------------------------
    RayTracer::RayTracer() :
      m_texture(PinnedHandle<Texture2D>::make_pinned()),
      m_world(nullptr),
      m_currentLine(-1)
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

      if (Input::isKeyPressed(GLFW_KEY_R) && 
          m_currentLine < 0)
      {
        startRaycast();
      }
    }

    //------------------------------------------------------------------------------------------------
    void RayTracer::onUpdate(float elapsedGameTime)
    {
      Inherited::onUpdate(elapsedGameTime);

      if (m_currentLine >= 0)
      {
        raycastCurrentLine();
      }

      if (m_currentLine >= 0)
      {
        raycastCurrentLine();
      }

      if (m_currentLine >= 0)
      {
        raycastCurrentLine();
      }
    }

    //------------------------------------------------------------------------------------------------
    void RayTracer::onDeath()
    {
      Inherited::onDeath();

      m_texture->unload();
      m_world.release();
      m_currentLine = -1;
    }

    //------------------------------------------------------------------------------------------------
    void RayTracer::startRaycast()
    {
      m_world.reset(new World(500, 500));

      Lua::LuaState::script(Path(CelesteEngine::Resources::getResourcesDirectory(), "Scripts", "World.lua"));
      Lua::LuaState::instance()["build"](*this);

     /* m_world->addObject(new Sphere(Point3D(0, 0, 0), 85, RGBColor(1, 0, 0)));
      m_world->addObject(new Sphere(Point3D(100, 100, 0), 50, RGBColor(0, 1, 0)));
      m_world->addObject(new Sphere(Point3D(-100, -100, 0), 50, RGBColor(0, 0, 1)));
      m_world->addObject(new Sphere(Point3D(0, 0, -100), 200, RGBColor(1, 1, 1)));*/
      m_world->build();

      m_texture->unload();
      m_texture->generate(m_world->vp.hres, m_world->vp.vres, nullptr);
      getGameObject()->findComponent<Rendering::SpriteRenderer>()->setTexture(m_texture.handle());
      getGameObject()->findComponent<Rendering::SpriteRenderer>()->setDimensions(m_texture->getDimensions());

      m_currentLine = 0;
    }

    //------------------------------------------------------------------------------------------------
    void RayTracer::raycastCurrentLine()
    {
      if (m_currentLine < m_world->vp.vres)
      {
        m_world->renderLine(m_currentLine, m_texture.handle());
        ++m_currentLine;
      }
      else
      {
        m_currentLine = -1;
      }
    }
  }
}