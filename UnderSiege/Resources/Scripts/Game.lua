package.path = Resources.getResourcesDirectory() .. "\\..\\..\\CelesteEngine\\Resources\\Scripts\\?.lua;" .. package.path

require "Engine"

local settingsPath = path.combine(Resources.getResourcesDirectory(), "Data", "Settings", "GameSettings.asset")
local settings = GameSettings.load(settingsPath)

setMasterVolume(settings:getMasterVolume())
setMusicVolume(settings:getMusicVolume())
setSFXVolume(settings:getSFXVolume())

loadScreen(path.combine(Resources.getResourcesDirectory(), "Data", "Screens", "DebugTools.asset"))
loadScreen(path.combine(Resources.getResourcesDirectory(), "Data", "Screens", "PersistentStartupAndMainMenu.asset"))
loadScreen(path.combine(Resources.getResourcesDirectory(), "Data", "Screens", "SplashScreen.asset"))