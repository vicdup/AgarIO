#include "Entity.h"
#include "Global.h"
#include <SFML/Graphics.hpp>


Entity::Entity() : sf::CircleShape(5), m_currentX(rand() % worldSize + 1), m_currentY(rand() % worldSize + 1)
{
	setPosition(sf::Vector2f(m_currentX, m_currentY));
	setFillColor(sf::Color::Blue);
	m_size = 5;
}

Entity::~Entity()
{
}

sf::Vector2f Entity
::getCenter()
{
	sf::Vector2f r(this->getPosition().x + m_size, this->getPosition().y + m_size);
	return r;
}

int Entity
::getSize()
{
	return m_size;
}