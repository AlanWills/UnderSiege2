package.path = getResourcesDirectory() .. "\\..\\..\\CelesteEngine\\CelesteEngine\\Resources\\Scripts\\?.lua;" .. package.path

require "Engine"

loadScreen(path.combine(getResourcesDirectory(), "Data", "Screens", "RayTracer.asset"))