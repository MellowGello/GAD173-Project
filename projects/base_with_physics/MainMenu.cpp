#include "MainMenu.h"
#include "SceneManager.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}


bool MainMenu::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window->getSize().x) / resolution.x, float(m_window->getSize().y) / resolution.y);

	
	if (!fontText.loadFromFile("data/Cousine-Regular.ttf"))
	{
		std::cout << "Error Font Load" << std::endl;
	}
	
	MenuOffset = 125;
	EachMenuOffset = 100;
	CenterWindow = sf::Vector2f(m_window->getSize().x / 2, m_window->getSize().y / 2);


	//Naming the Menu
	MenuText[0].setString("Play");
	MenuText[1].setString("Editor");
	MenuText[2].setString("Options");
	MenuText[3].setString("Exit");

	//Setting the text, font, and color of the Menu
	for (size_t i = 0; i < 4; i++)
	{
		MenuText[i].setFont(fontText);
		MenuText[i].setColor(sf::Color(175, 175, 175));
		MenuText[i].setPosition(sf::Vector2f(CenterWindow.x - (MenuText[i].getGlobalBounds().width / 2)
			,CenterWindow.y - (MenuText[i].getGlobalBounds().height / 2) + (EachMenuOffset * i) + (MenuOffset)));
	}
	MenuText[MenuSelect].setColor(sf::Color(255, 255, 255));

	return true;
}

void MainMenu::update(float deltaT)
{
	//Moving the Menu Selection Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
	{
		if (UpButton)
		{
			MenuSelect--;
			if (MenuSelect < 0)
			{
				MenuSelect = 3;
			}
			for (size_t i = 0; i < 4; i++)
			{
				MenuText[i].setColor(sf::Color(175, 175, 175));
			}
			MenuText[MenuSelect].setColor(sf::Color(255, 255, 255));
			UpButton = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == false)
	{
		UpButton = true;
	}
	//Moving the Menu Selection Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (DownButton)
		{
			MenuSelect++;
			if (MenuSelect > 3)
			{
				MenuSelect = 0;
			}

			for (size_t i = 0; i < 4; i++)
			{
				MenuText[i].setColor(sf::Color(175, 175, 175));
			}
			MenuText[MenuSelect].setColor(sf::Color(255, 255, 255));
			DownButton = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == false)
	{
		DownButton = true;
	}


	//Brings the player into the 'game' scene//
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (MenuSelect == 0)
		{
			SceneManager::Run(1);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (MenuSelect == 1)
		{
			SceneManager::Run(2);
		}
	}
}

void MainMenu::render()
{
	//m_window.draw(*m_backgroundSprite);
	for (size_t i = 0; i < 4; i++)
	{
		m_window->draw(MenuText[i]);
	}
}

void MainMenu::cleanup()
{
	delete m_backgroundSprite;
}

