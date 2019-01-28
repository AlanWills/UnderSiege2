package.path = getResourcesDirectory() .. "\\..\\..\\CelesteEngine\\CelesteEngine\\Resources\\?.lua;" .. package.path

require "Scripts.Engine"

loadScreen(path.combine(getResourcesDirectory(), "Data", "Screens", "RayTracer.asset"))