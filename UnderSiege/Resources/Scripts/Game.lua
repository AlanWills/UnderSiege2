package.path = getResourcesDirectory() .. "\\..\\..\\CelesteEngine\\CelesteEngine\\Resources\\?.lua;" .. package.path

require "Scripts.Engine"

local settingsPath = path.combine(getResourcesDirectory(), "Data", "Settings", "GameSettings.asset")
local settings = GameSettings.load(settingsPath)

setMasterVolume(settings:getMasterVolume())
setMusicVolume(settings:getMusicVolume())
setSFXVolume(settings:getSFXVolume())

loadScreen(path.combine(getResourcesDirectory(), "Data", "Screens", "DebugTools.asset"))
loadScreen(path.combine(getResourcesDirectory(), "Data", "Screens", "PersistentStartupAndMainMenu.asset"))
loadScreen(path.combine(getResourcesDirectory(), "Data", "Screens", "SplashScreen.asset"))