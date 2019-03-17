package.path = Resources.getResourcesDirectory() .. "\\..\\..\\CelesteEngine\\CelesteEngine\\Resources\\Scripts\\?.lua;" .. package.path

require "Engine"

Screen.load(path.combine(Resources.getResourcesDirectory(), "Data", "Screens", "RayTracer.asset"))