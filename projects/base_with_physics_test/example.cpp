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
	kage::Physics::init(b2Vec2(0, 9.8));
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	Ball = kage::TextureManager::getSprite("data/Ball.png");
	Ball->setPosition(m_window.getSize().x / 2, m_window.getSize().y / 2);

	Paddle = kage::TextureManager::getSprite("data/Paddle.png");
	Paddle->setPosition(0, Paddle_Y);
	PaddleCenter = Paddle->getGlobalBounds().width / 2;

	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	return true;
}

void Example::update(float deltaT)
{

	sf::Vector2f MousePointer = (sf::Vector2f)sf::Mouse::getPosition(m_window);
	Paddle->setPosition(MousePointer.x - PaddleCenter, Paddle_Y);

	BallPos = Ball->getPosition();
	Ball->setPosition(BallPos.x + SpeedX,BallPos.y + SpeedY);
	
	if (Ball->getPosition().y + Ball_Height >= m_window.getSize().y )
	{
		Ball->setPosition(Paddle->getPosition().x + PaddleCenter, Paddle_Y - 30);
	}

	if (Ball->getPosition().y <= 0)
	{
		SpeedY = -SpeedY;
	}

	if (Ball->getPosition().x + Ball_Width >= m_window.getSize().x)
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
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
	m_window.draw(*Ball);
	m_window.draw(*Paddle);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

