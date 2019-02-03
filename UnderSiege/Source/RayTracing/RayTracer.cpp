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

      if (Input::isKeyPressed(GLFW_KEY_R))
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
      Lua::LuaState::script(Path(CelesteEngine::Resources::getResourcesDirectory(), "Scripts", "World.lua"));
      
      glm::vec2 worldDimensions(500);
      CelesteEngine::deserialize<glm::vec2>(Lua::LuaState::instance()["dimensions"].get_or<std::string>("500,500"), worldDimensions);
      m_world.reset(new World(worldDimensions.x, worldDimensions.y));
      m_world->setRayZPosition(Lua::LuaState::instance()["ray_z_position"].get_or(100.0f));
      
      Lua::LuaState::instance()["build"](*this);
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