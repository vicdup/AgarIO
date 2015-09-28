#include "Bubble.h"
#include "Global.h"
#include <SFML/Graphics.hpp>

using namespace std;


Bubble::Bubble(): Entity()
{
	m_currentY = 100;
	m_currentX=100;
	setPosition(sf::Vector2f(m_currentX, m_currentY));
	setSize(10);
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

void Bubble::Eat(float size)
{
	m_size = sqrt(getRadius()*getRadius() + size*size);
	setSize(m_size);
}

void Bubble::setSize(float radius)
{
	setRadius(radius);
	m_size = radius;
	m_speed = 40 / radius;
}

Bubble Bubble::Split()
{
	Bubble bubble;
	bubble.setSize(this->getSize() / sqrt(2));
	this->setSize(bubble.getSize());
	bubble.setPosition(getPosition().x + 10, getPosition().y + 10);
	return bubble;
}
