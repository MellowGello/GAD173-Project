#pragma once

#include "app.h"

#define X_Offset 10
#define Y_Offset 15

#define X_Cell 10
#define X_Length 100
#define Y_Cell 10
#define Y_Length 100

#define LineThickness 5
#define LineArraySize 11
#define RealCellSize LineArraySize - 1
#define FullCellSize (RealCellSize) * (RealCellSize)

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

	sf::Sprite *m_backgroundSprite;
	sf::Sprite *m_catSprite;
	sf::Texture *m_catTexture;

	sf::Texture* m_dirtBlockTexture;
	sf::Sprite *m_dirtBlockSprite;
	bool b_dirtGrab;

	sf::Texture* m_waterBlockTexture;
	sf::Sprite *m_waterBlockSprite;
	bool b_waterGrab;

	sf::Texture* m_grassBlockTexture;
	sf::Sprite* m_grassBlockSprite;
	bool b_grassGrab;

	sf::Texture* m_stoneBlockTexture;
	sf::Sprite* m_stoneBlockSprite;
	bool b_stoneGrab;

	sf::Texture *m_plainTexture;
	sf::Sprite* m_plainSprite;

	sf::RectangleShape LineH[LineArraySize];
	sf::RectangleShape LineV[LineArraySize];

	sf::Sprite Tiles [FullCellSize];
};
