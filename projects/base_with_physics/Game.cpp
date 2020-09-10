#include "Game.h"
#include "SceneManager.h"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::start()
{

	m_backgroundSprite = kage::TextureManager::getSprite("data/grass_1024.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window->getSize().x) / resolution.x, float(m_window->getSize().y) / resolution.y);

	return true;
}

void Game::update(float deltaT)
{
	ImGui::Begin("Kage2D");
	if (ImGui::Button("Return to Main Menu"))
	{
		SceneManager::Run(0);
	}
	ImGui::End();
}

void Game::render()
{
	m_window->draw(*m_backgroundSprite);
}

void Game::cleanup()
{
	delete m_backgroundSprite;
}