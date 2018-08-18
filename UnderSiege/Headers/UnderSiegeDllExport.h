#pragma once

#ifdef BUILDING_UNDER_SIEGE_DLL
#define UnderSiegeDllExport __declspec(dllexport)
#else
#define UnderSiegeDllExport __declspec(dllimport)
#endif
