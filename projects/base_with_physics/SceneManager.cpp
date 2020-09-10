#include "SceneManager.h"

static int currentScene = 0;
static std::vector<Scene*> ScenesList;
SceneManager::SceneManager() : App()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::AddScene(Scene* scene)
{
	ScenesList.push_back(scene);
	scene->m_window = &m_window;
}

void SceneManager::Run(int index)
{
	currentScene = index;
	ScenesList[currentScene]->start();
}

bool SceneManager::start()
{
	return ScenesList[currentScene]->start();
}

void SceneManager::update(float deltaT)
{
	ScenesList[currentScene]->update(deltaT);
}

void SceneManager::render()
{
	ScenesList[currentScene]->render();
}

void SceneManager::cleanup()
{
	ScenesList[currentScene]->cleanup();
}
