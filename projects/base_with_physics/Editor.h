#pragma once
#include "tile.h"
#include "Scene.h"

#define X_Offset 10
#define Y_Offset 15

#define X_Cell 10
#define X_Length 100
#define Y_Cell 10
#define Y_Length 100

#define LineThickness 5
#define FullCellSize (X_Cell) * (Y_Cell)



class Editor : public Scene
{
public:
	Editor();
	virtual ~Editor();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Editor &inst();

	sf::Sprite *m_backgroundSprite;
	sf::Sprite *m_catSprite;
	sf::Texture *m_catTexture;

	sf::Sprite *m_dirtBlockSprite;
	bool b_dirtGrab;
	Tiles dirt;

	sf::Sprite *m_waterBlockSprite;
	bool b_waterGrab;
	Tiles water;

	sf::Sprite* m_grassBlockSprite;
	bool b_grassGrab;
	Tiles grass;

	sf::Sprite* m_stoneBlockSprite;
	bool b_stoneGrab;
	Tiles stone;

	sf::Sprite* m_plainSprite;
	Tiles plain;

	sf::Texture* m_currentTexture;

	int MapIntoFile[FullCellSize];

	sf::RectangleShape LineH[Y_Cell + 1];
	sf::RectangleShape LineV[X_Cell + 1];

	sf::Sprite Tiles [FullCellSize];


};
