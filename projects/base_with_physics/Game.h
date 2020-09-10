#pragma once
#include "Scene.h"

class Game : public Scene
{
	
public:
	Game();
	virtual ~Game();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();

	sf::Sprite* m_backgroundSprite;
};

