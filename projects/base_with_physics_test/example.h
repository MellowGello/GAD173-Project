#pragma once

#include "app.h"
#include "kage2dutil/physics.h"

#define Paddle_Y 1000
#define Ball_Width 25
#define Ball_Height 25
#define Speed 5
class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();

	float PaddleCenter = 0;
	float SpeedY = Speed;
	float SpeedX = Speed;
	sf::Vector2f BallPos;

	sf::Sprite *Ball;
	sf::Sprite *Paddle;

	sf::Sprite *m_backgroundSprite;
};
