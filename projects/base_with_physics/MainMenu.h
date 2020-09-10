#pragma once

#include "app.h"
#include "kage2dutil/physics.h"
#include "Scene.h"

class MainMenu : public Scene
{
public:
	MainMenu();
	virtual ~MainMenu();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();


	sf::Font fontText;
	sf::Text MenuText[3];

	sf::Vector2f CenterWindow;
	int MenuOffset;
	int EachMenuOffset;

	int MenuSelect = 0;

	bool DownButton = true;
	bool UpButton = true;

	sf::Sprite *m_backgroundSprite;
};
