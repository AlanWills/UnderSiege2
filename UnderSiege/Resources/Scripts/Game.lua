local test = path.combine("Test", "Path")
log(test)

setMasterVolume(0.5)
setMusicVolume(0.5)
setSFXVolume(0.5)

loadScreen(path.combine(getResourcesDirectory(), "Data", "Screens", "PersistentStartupAndMainMenu.asset"));
loadScreen(path.combine(getResourcesDirectory(), "Data", "Screens", "SplashScreen.asset"));