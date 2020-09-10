#include "cmath"
#include "kf/kf_log.h"
#include "SceneManager.h"
#include "MainMenu.h"
#include "Game.h"
#include "Editor.h"


using namespace std;

int main()
{
	SceneManager sceneClass;

	MainMenu* mainMenuWindow = new MainMenu();
	Game* gameWindow = new Game();
	Editor* editorWindow = new Editor();
	
	sceneClass.AddScene(mainMenuWindow);
	sceneClass.AddScene(gameWindow);
	sceneClass.AddScene(editorWindow);
	sceneClass.Run(0);

	sceneClass.run();

	return 0;
}
