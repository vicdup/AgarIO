#include "Bubble.h"
#include "Global.h"
#include <SFML/Graphics.hpp>

using namespace std;


Bubble::Bubble(): Entity()
{
	m_currentY = 100;
	m_speed = 5;
	m_currentX=100;
	setPosition(sf::Vector2f(m_currentX, m_currentY));
	setRadius(10);
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

void Bubble
::Eat(float size)
{
	m_size = sqrt(getRadius()*getRadius() + size*size);
	setRadius(m_size);
	m_speed = m_speed*0.95;
}