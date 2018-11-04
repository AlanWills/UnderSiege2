package.path = package.path .. ";" .. getResourcesDirectory() .. "\\?.lua"
local path = require "Scripts.Core.FileSystem.Path"

local settingsPath = path.combine(getResourcesDirectory(), "Data", "Settings", "GameSettings.asset")
local settings = loadScriptableObject("GameSettings", settingsPath);

setMasterVolume(settings:getMasterVolume())
setMusicVolume(settings:getMusicVolume())
setSFXVolume(settings:getSFXVolume())

deleteScriptableObject(settings)

loadScreen(path.combine(getResourcesDirectory(), "Data", "Screens", "PersistentStartupAndMainMenu.asset"));
loadScreen(path.combine(getResourcesDirectory(), "Data", "Screens", "SplashScreen.asset"));