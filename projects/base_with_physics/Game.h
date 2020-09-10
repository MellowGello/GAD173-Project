#pragma once
#include "Scene.h"
#define Paddle_Y 1000
#define Ball_Width 25
#define Ball_Height 25
#define Speed 5

class Game : public Scene
{
	
public:
	Game();
	virtual ~Game();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();

	float PaddleCenter = 0;
	float SpeedY = Speed;
	float SpeedX = Speed;
	sf::Vector2f BallPos;

	sf::Sprite* Ball;
	sf::Sprite* Paddle;

	sf::Sprite* m_backgroundSprite;
};

