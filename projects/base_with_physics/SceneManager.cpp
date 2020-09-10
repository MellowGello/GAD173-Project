#include "SceneManager.h"

static int currentScene = 0;
static std::vector<Scene*> Scenes;
SceneManager::SceneManager() : App()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::AddScene(Scene* scene)
{
	Scenes.push_back(scene);
	scene->m_window = &m_window;
}

void SceneManager::Run(int index)
{
	currentScene = index;
	Scenes[currentScene]->start();
}

bool SceneManager::start()
{
	return Scenes[currentScene]->start();
}

void SceneManager::update(float deltaT)
{
	Scenes[currentScene]->update(deltaT);
}

void SceneManager::render()
{
	Scenes[currentScene]->render();
}

void SceneManager::cleanup()
{
	Scenes[currentScene]->cleanup();
}
