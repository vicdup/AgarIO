#include "Food.h"
#include <SFML/Graphics.hpp>

Food::Food() : sf::CircleShape(10), m_currentX(rand() % 800 + 1), m_currentY(rand() % 600 + 1), m_speed(5)
{
	setPosition(sf::Vector2f(m_currentX, m_currentY));
	setFillColor(sf::Color::Blue);
	m_size = 10;
}

Food::~Food()
{
}

void Food
::Move(float mouseX, float mouseY)
{

	float relativeCenterMouseX = mouseX - (this->getPosition().x + m_size);
	float relativeCenterMouseY = mouseY - (this->getPosition().y + m_size);
	if (abs(relativeCenterMouseX) > 3 || abs(relativeCenterMouseY) > 3)
	{
		float c = sqrt((m_speed*m_speed) / (relativeCenterMouseX*relativeCenterMouseX + relativeCenterMouseY*relativeCenterMouseY));
		move(sf::Vector2f(c*relativeCenterMouseX, c*relativeCenterMouseY));
	}

}

sf::Vector2f Food
::getCenter()
{
	sf::Vector2f r(this->getPosition().x + m_size, this->getPosition().y + m_size);
	return r;
}

int Food
::getSize()
{
	return m_size;
}