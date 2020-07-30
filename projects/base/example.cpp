#include "example.h"

Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	//Cat Sprite and Texture
	m_catSprite = kage::TextureManager::getSprite("data/cat.png");
	m_catSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	m_catTexture = kage::TextureManager::getTexture("data/cat.png");

	//Dirt Block Sprite and Texture
	m_dirtBlockSprite = kage::TextureManager::getSprite("data/cute/Dirt Block.png");
	m_dirtBlockTexture = kage::TextureManager::getTexture("data/cute/Dirt Block.png");

	//Water Block Sprite and Texture
	m_waterBlockSprite = kage::TextureManager::getSprite("data/cute/Water Block.png");
	m_waterBlockTexture = kage::TextureManager::getTexture("data/cute/Water Block.png");

	//Plain Tiles Sprite and Texture
	m_plainSprite = kage::TextureManager::getSprite("data/cute/Plain Block.png");
	m_plainTexture = kage::TextureManager::getTexture("data/cute/Plain Block.png");

	//Grass Tiles Sprite and Texture
	m_grassBlockSprite = kage::TextureManager::getSprite("data/cute/Grass Block.png");
	m_grassBlockTexture = kage::TextureManager::getTexture("data/cute/Grass Block.png");

	//Stone Tile Sprite and Texture
	m_stoneBlockSprite = kage::TextureManager::getSprite("data/cute/Stone Block.png");
	m_stoneBlockTexture = kage::TextureManager::getTexture("data/cute/Stone Block.png");

	//Placing Tiles
	m_dirtBlockSprite->setPosition(1754, 300);
	m_waterBlockSprite->setPosition(1754, 500);
	m_grassBlockSprite->setPosition(1754, 700);
	m_stoneBlockSprite->setPosition(1754, 900);

	for (size_t i = 0; i < LineArraySize; i++)
	{
		//Horizontal Line
		LineH[i] = sf::RectangleShape(sf::Vector2f(X_Length * (RealCellSize), LineThickness));
		LineH[i].setPosition(sf::Vector2f(0, X_Length * i));
		LineH[i].setFillColor(sf::Color(sf::Uint8(255),sf::Uint8(150),sf::Uint8(150), sf::Uint8(255)));

		//Vertical Line
		LineV[i] = sf::RectangleShape(sf::Vector2f(LineThickness, Y_Length * (RealCellSize)+ LineThickness));
		LineV[i].setPosition(sf::Vector2f(Y_Length * i, 0));
		LineV[i].setFillColor(sf::Color(sf::Uint8(255), sf::Uint8(150), sf::Uint8(150), sf::Uint8(255)));
	}

	//Setting Tiles Calculation.
	for (size_t y = 0; y < X_Cell; y++)
	{
		for (size_t x = 0; x < X_Cell; x++)
		{
			Tiles[x + y * X_Cell].setPosition(sf::Vector2f(x * Y_Length,y * X_Length));
			Tiles[x + y * X_Cell].setTexture(*m_plainTexture);
		}
		
	}

	return true;
}

void Example::update(float deltaT)
{
	sf::Vector2f MousePointer = (sf::Vector2f)sf::Mouse::getPosition(m_window);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	//Placing on the right tiles.
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_window.hasFocus())
	{
		int MouseX = MousePointer.x;
		int MouseY = MousePointer.y;
		int Index = (MouseX / X_Length) + (MouseY / Y_Length) * (RealCellSize);

		if ((MouseX < X_Length * X_Cell) && (MouseY < Y_Length * Y_Cell))
		{
			if (b_dirtGrab)
			{
				Tiles[Index].setTexture(*m_dirtBlockTexture);
			}
			else if (b_waterGrab) 
			{
				Tiles[Index].setTexture(*m_waterBlockTexture);
			}
			else if (b_grassGrab)
			{
				Tiles[Index].setTexture(*m_grassBlockTexture);
			}
			else if (b_stoneGrab)
			{
				Tiles[Index].setTexture(*m_stoneBlockTexture);
			}
		}
		
		//Selecting Tiles
		//Dirt Block
		if (MouseX > 1754 && MouseX < 1852 && MouseY > 300 && MouseY < 421)
		{
			b_dirtGrab = true;
			b_waterGrab = false;
			b_grassGrab = false;
			b_stoneGrab = false;
		}
		//Water Block
		if (MouseX > 1754 && MouseX < 1754 + 99 && MouseY > 500 && MouseY < 500 + 123)
		{
			b_dirtGrab = false;
			b_waterGrab = true;
			b_grassGrab = false;
			b_stoneGrab = false;
		}
		//Grass Block
		if (MouseX > 1754 && MouseX < 1754 + 99 && MouseY > 700 && MouseY < 700 + 123)
		{
			b_dirtGrab = false;
			b_waterGrab = false;
			b_grassGrab = true;
			b_stoneGrab = false;
		}
		//Stone Block
		if (MouseX > 1754 && MouseX < 1754 + 99 && MouseY > 900 && MouseY < 900 + 123)
		{
			b_dirtGrab = false;
			b_waterGrab = false;
			b_grassGrab = false;
			b_stoneGrab = true;
		}
	}
	
	//Removing Tiles
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_window.hasFocus())
	{
		int MouseX = MousePointer.x;
		int MouseY = MousePointer.y;
		int Index = (MouseX / X_Length) + (MouseY / Y_Length) * (RealCellSize);

		if ((MouseX < X_Length * X_Cell) && (MouseY < Y_Length * Y_Cell))
		{
			Tiles[Index].setTexture(*m_plainTexture);
		}
	}

	std::cout << MousePointer.x << " / " << MousePointer.y << std::endl;

	//Position of Sprites
	if (b_dirtGrab) 
	{
		m_dirtBlockSprite->setPosition(MousePointer.x, MousePointer.y);
		m_waterBlockSprite->setPosition(1754, 500);
		m_grassBlockSprite->setPosition(1754, 700);
		m_stoneBlockSprite->setPosition(1754, 900);
		m_catSprite->setPosition(1754, 300);
	}
	else if (b_waterGrab)
	{
		m_dirtBlockSprite->setPosition(1754,300);
		m_waterBlockSprite->setPosition(MousePointer.x, MousePointer.y);
		m_grassBlockSprite->setPosition(1754, 700);
		m_stoneBlockSprite->setPosition(1754, 900);
		m_catSprite->setPosition(1754, 500);
	}
	else if (b_grassGrab)
	{
		m_dirtBlockSprite->setPosition(1754, 300);
		m_waterBlockSprite->setPosition(1754, 500);
		m_grassBlockSprite->setPosition(MousePointer.x, MousePointer.y);
		m_stoneBlockSprite->setPosition(1754, 900);
		m_catSprite->setPosition(1754, 700);
	}
	else if (b_stoneGrab)
	{
		m_dirtBlockSprite->setPosition(1754, 300);
		m_waterBlockSprite->setPosition(1754, 500);
		m_grassBlockSprite->setPosition(1754, 700);
		m_stoneBlockSprite->setPosition(MousePointer.x, MousePointer.y);
		m_catSprite->setPosition(1754, 900);
	}
	else
	{
		m_catSprite->setPosition(MousePointer.x - 50, MousePointer.y - 75);
	}

	ImGui::Begin("Kage2D");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	m_window.draw(*m_catSprite);
	m_window.draw(*m_dirtBlockSprite);
	m_window.draw(*m_waterBlockSprite);
	m_window.draw(*m_grassBlockSprite);
	m_window.draw(*m_stoneBlockSprite);

	for (size_t i = 0; i < LineArraySize; i++)
	{
		m_window.draw(LineH[i]);
		m_window.draw(LineV[i]);
	}

	for (size_t i = 0; i < (FullCellSize); i++)
	{
		m_window.draw(Tiles[i]);
	}
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

