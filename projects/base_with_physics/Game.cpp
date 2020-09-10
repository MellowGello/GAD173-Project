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

	Ball = kage::TextureManager::getSprite("data/Ball.png");
	Ball->setPosition(m_window->getSize().x / 2, m_window->getSize().y / 2);

	Paddle = kage::TextureManager::getSprite("data/Paddle.png");
	Paddle->setPosition(0, Paddle_Y);
	PaddleCenter = Paddle->getGlobalBounds().width / 2;

	m_backgroundSprite->setScale(float(m_window->getSize().x) / resolution.x, float(m_window->getSize().y) / resolution.y);

	return true;
}

void Game::update(float deltaT)
{
	sf::Vector2f MousePointer = (sf::Vector2f)sf::Mouse::getPosition(*m_window);
	Paddle->setPosition(MousePointer.x - PaddleCenter, Paddle_Y);

	BallPos = Ball->getPosition();
	Ball->setPosition(BallPos.x + SpeedX, BallPos.y + SpeedY);

	if (Ball->getPosition().y + Ball_Height >= m_window->getSize().y)
	{
		Ball->setPosition(Paddle->getPosition().x + PaddleCenter, Paddle_Y - 30);
	}

	if (Ball->getPosition().y <= 0)
	{
		SpeedY = -SpeedY;
	}

	if (Ball->getPosition().x + Ball_Width >= m_window->getSize().x)
	{
		SpeedX = -SpeedX;
	}
	else if (Ball->getPosition().x <= 0)
	{
		SpeedX = -SpeedX;
	}

	if (Ball->getPosition().y + Ball_Height >= Paddle_Y &&
		Ball->getPosition().x >= Paddle->getPosition().x && Ball->getPosition().x <= Paddle->getPosition().x + Paddle->getGlobalBounds().width)
	{
		SpeedY = -SpeedY;
	}

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
	m_window->draw(*Ball);
	m_window->draw(*Paddle);
}

void Game::cleanup()
{
	delete m_backgroundSprite;
}