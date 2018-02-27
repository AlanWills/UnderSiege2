#pragma once

#include "Callbacks/Callback.h"


namespace US
{

struct LoadLevel
{
  DECLARE_CALLBACK(LoadLevel, "LoadLevel")

  public:
    void operator()(const CelesteEngine::Handle<CelesteEngine::GameObject>& gameObject, const std::string& arg);
};

}