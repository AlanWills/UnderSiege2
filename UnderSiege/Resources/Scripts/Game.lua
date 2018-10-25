package.path = package.path .. ";" .. getResourcesDirectory() .. "\\?.lua"
local path = require "Scripts.Core.FileSystem.Path"

function test()
	local settings = instantiateScriptableObject("GameSettings");

	setMasterVolume(0.5)
	setMusicVolume(0.5)
	setSFXVolume(0.5)

	deleteScriptableObject(settings)

	loadScreen(path.combine(getResourcesDirectory(), "Data", "Screens", "PersistentStartupAndMainMenu.asset"));
	loadScreen(path.combine(getResourcesDirectory(), "Data", "Screens", "SplashScreen.asset"));
end