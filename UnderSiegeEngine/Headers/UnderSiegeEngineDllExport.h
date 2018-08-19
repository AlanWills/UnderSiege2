#pragma once

#ifdef BUILDING_UNDER_SIEGE_ENGINE_DLL
#define UnderSiegeEngineDllExport __declspec(dllexport)
#else
#define UnderSiegeEngineDllExport __declspec(dllimport)
#endif
