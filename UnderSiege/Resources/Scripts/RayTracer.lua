package.path = Resources.getResourcesDirectory() .. "\\..\\..\\CelesteEngine\\CelesteEngine\\Resources\\Scripts\\?.lua;" .. package.path

require "Engine"

loadScreen(path.combine(Resources.getResourcesDirectory(), "Data", "Screens", "RayTracer.asset"))