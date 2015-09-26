#include "Bubble.h"
#include <SFML/Graphics.hpp>

Bubble::Bubble(): sf::CircleShape(20),m_currentX(100),m_currentY(100),m_speed(5)
{
	setPosition(sf::Vector2f(m_currentX, m_currentY));
	setFillColor(sf::Color::Red);
	m_size = 20;
}

Bubble::~Bubble()
{
}

void Bubble::Move(float mouseX, float mouseY)
{

	float relativeCenterMouseX = mouseX - (this->getPosition().x+m_size);
	float relativeCenterMouseY = mouseY - (this->getPosition().y+m_size);
	if (abs(relativeCenterMouseX)>3 || abs(relativeCenterMouseY)>3)
	{
		float c = sqrt((m_speed*m_speed) / (relativeCenterMouseX*relativeCenterMouseX + relativeCenterMouseY*relativeCenterMouseY));
		move(sf::Vector2f(c*relativeCenterMouseX, c*relativeCenterMouseY));
	} 

}

sf::Vector2f Bubble
::getCenter()
{
	sf::Vector2f r(this->getPosition().x + m_size, this->getPosition().y + m_size);
	return r;
}

int Bubble
::getSize()
{
	return m_size;
}

void Bubble
::Eat(int size)
{
	setRadius(getRadius()+5);
	m_size = getRadius();
}