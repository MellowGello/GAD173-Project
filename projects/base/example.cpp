#include "example.h"
#include <iostream>
#include <fstream>

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

	//Plain Tiles Sprite and Texture
	m_plainSprite = kage::TextureManager::getSprite("data/cute/Plain Block.png");
	plain.m_Texture = kage::TextureManager::getTexture("data/cute/Plain Block.png");
	plain.id = 0;

	//Dirt Block Sprite and Texture
	m_dirtBlockSprite = kage::TextureManager::getSprite("data/cute/Dirt Block.png");
	dirt.m_Texture = kage::TextureManager::getTexture("data/cute/Dirt Block.png");
	dirt.id = 1;

	//Water Block Sprite and Texture
	m_waterBlockSprite = kage::TextureManager::getSprite("data/cute/Water Block.png");
	water.m_Texture = kage::TextureManager::getTexture("data/cute/Water Block.png");
	water.id = 2;

	//Grass Tiles Sprite and Texture
	m_grassBlockSprite = kage::TextureManager::getSprite("data/cute/Grass Block.png");
	grass.m_Texture = kage::TextureManager::getTexture("data/cute/Grass Block.png");
	grass.id = 3;

	//Stone Tile Sprite and Texture
	m_stoneBlockSprite = kage::TextureManager::getSprite("data/cute/Stone Block.png");
	stone.m_Texture = kage::TextureManager::getTexture("data/cute/Stone Block.png");
	stone.id = 4;

	m_currentTexture = kage::TextureManager::getTexture("data/cute/Plain Block.png");

	//Placing Tiles
	m_dirtBlockSprite->setPosition(1754, 300);
	m_waterBlockSprite->setPosition(1754, 500);
	m_grassBlockSprite->setPosition(1754, 700);
	m_stoneBlockSprite->setPosition(1754, 900);

	for (size_t i = 0; i < Y_Cell; i++)
	{
		//Horizontal Line
		LineH[i] = sf::RectangleShape(sf::Vector2f(X_Length * (Y_Cell), LineThickness));
		LineH[i].setPosition(sf::Vector2f(0, Y_Length * i));
		LineH[i].setFillColor(sf::Color(sf::Uint8(255),sf::Uint8(150),sf::Uint8(150), sf::Uint8(255)));
	}

	for (size_t i = 0; i < X_Cell; i++)
	{
		//Vertical Line
		LineV[i] = sf::RectangleShape(sf::Vector2f(LineThickness, Y_Length * (X_Cell)+LineThickness));
		LineV[i].setPosition(sf::Vector2f(X_Length * i, 0));
		LineV[i].setFillColor(sf::Color(sf::Uint8(255), sf::Uint8(150), sf::Uint8(150), sf::Uint8(255)));
	}

	//Setting Tiles Calculation.
	for (size_t y = 0; y < X_Cell; y++)
	{
		for (size_t x = 0; x < X_Cell; x++)
		{
			Tiles[x + y * X_Cell].setPosition(sf::Vector2f(x * X_Length,y * Y_Length));
			Tiles[x + y * X_Cell].setTexture(*plain.m_Texture);
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
		int Index = (MouseX / X_Length) + (MouseY / Y_Length) * (X_Cell);

		if ((MouseX < X_Length * X_Cell) && (MouseY < Y_Length * Y_Cell))
		{
				Tiles[Index].setTexture(*m_currentTexture);	
		}
		
		//Selecting Tiles
		//Dirt Block
		if (MouseX > 1754 && MouseX < 1852 && MouseY > 300 && MouseY < 421)
		{
			b_dirtGrab = true;
			b_waterGrab = false;
			b_grassGrab = false;
			b_stoneGrab = false;

			m_currentTexture = kage::TextureManager::getTexture("data/cute/Dirt Block.png");
		}
		//Water Block
		if (MouseX > 1754 && MouseX < 1754 + 99 && MouseY > 500 && MouseY < 500 + 123)
		{
			b_dirtGrab = false;
			b_waterGrab = true;
			b_grassGrab = false;
			b_stoneGrab = false;

			m_currentTexture = kage::TextureManager::getTexture("data/cute/Water Block.png");
		}
		//Grass Block
		if (MouseX > 1754 && MouseX < 1754 + 99 && MouseY > 700 && MouseY < 700 + 123)
		{
			b_dirtGrab = false;
			b_waterGrab = false;
			b_grassGrab = true;
			b_stoneGrab = false;

			m_currentTexture = kage::TextureManager::getTexture("data/cute/Grass Block.png");
		}
		//Stone Block
		if (MouseX > 1754 && MouseX < 1754 + 99 && MouseY > 900 && MouseY < 900 + 123)
		{
			b_dirtGrab = false;
			b_waterGrab = false;
			b_grassGrab = false;
			b_stoneGrab = true;

			m_currentTexture = kage::TextureManager::getTexture("data/cute/Stone Block.png");
		}
	}
	
	//Removing Tiles
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_window.hasFocus())
	{
		int MouseX = MousePointer.x;
		int MouseY = MousePointer.y;
		int Index = (MouseX / X_Length) + (MouseY / Y_Length) * (X_Cell);

		if ((MouseX < X_Length * X_Cell) && (MouseY < Y_Length * Y_Cell))
		{
			Tiles[Index].setTexture(*plain.m_Texture);
		}
	}

	//std::cout << MousePointer.x << " / " << MousePointer.y << std::endl;

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

	//======//
	//Saving//
	//======//

	if (ImGui::Button("Save"))
	{
		
		std::ofstream myfile;
		myfile.open("Map.txt");
		for (size_t y = 0; y < Y_Cell; y++)
		{
			for (size_t x = 0; x < X_Cell; x++)
			{
				if (Tiles[x + y * X_Cell].getTexture() == plain.m_Texture)
				{
					MapIntoFile[x + y * X_Cell] = 0;
				}
				else if (Tiles[x + y * X_Cell].getTexture() == dirt.m_Texture)
				{
					MapIntoFile[x + y * X_Cell] = 1;
				}
				else if (Tiles[x + y * X_Cell].getTexture() == water.m_Texture)
				{
					MapIntoFile[x + y * X_Cell] = 2;
				}
				else if (Tiles[x + y * X_Cell].getTexture() == grass.m_Texture)
				{
					MapIntoFile[x + y * X_Cell] = 3;
				}
				else if (Tiles[x + y * X_Cell].getTexture() == stone.m_Texture)
				{
					MapIntoFile[x + y * X_Cell] = 4;
				}
				myfile << MapIntoFile[x + y * X_Cell] << ",";
			}
			myfile << "\n";
		}
		myfile.close();	
	}

	//======//
	//Loading//
	//======//

	if (ImGui::Button("Load"))
	{
		std::string line;
		std::ifstream myOtherFile("Map.txt");
		if (myOtherFile.is_open())
		{
			int y = 0;
			while (getline(myOtherFile, line))
			{
				int cutter = 0;
				for (size_t x = 0; x < X_Cell; x++)
				{
					int commaIndex = line.find(',');
					std::string stringGet = line.substr(cutter, commaIndex);
					int element = std::stoi(stringGet);
					cutter += (stringGet.length() + commaIndex);

					switch (element)
					{
					case 0:
						Tiles[x + y * X_Cell].setTexture(*plain.m_Texture);
						break;

					case 1:
						Tiles[x + y * X_Cell].setTexture(*dirt.m_Texture);
						break;

					case 2:
						Tiles[x + y * X_Cell].setTexture(*water.m_Texture);
						break;

					case 3:
						Tiles[x + y * X_Cell].setTexture(*grass.m_Texture);
						break;

					case 4:
						Tiles[x + y * X_Cell].setTexture(*stone.m_Texture);
						break;

					default:
						break;
					}
				}
				y++;
			}
			myOtherFile.close();
		}
		else std::cout << "Unable to open file";
	}

	//======//
	//Reset//
	//======//

	if (ImGui::Button("Reset"))
	{
		for (size_t y = 0; y < X_Cell; y++)
		{
			for (size_t x = 0; x < X_Cell; x++)
			{
				Tiles[x + y * X_Cell].setTexture(*plain.m_Texture);
			}
		}
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

	for (size_t i = 0; i < Y_Cell; i++)
	{
		m_window.draw(LineH[i]);
	}

	for (size_t i = 0; i < X_Cell; i++)
	{
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

