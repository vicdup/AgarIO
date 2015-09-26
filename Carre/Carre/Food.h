#include <string>
#include <SFML/Graphics.hpp>

class Food :public sf::CircleShape
{
public:
	Food();
	~Food();
	void Move(float mouseX, float mouseY);
	sf::Vector2f getCenter();
	int getSize();

private:
	int m_size;
	int m_speed;
	int m_currentX;
	int m_currentY;
	std::string m_color;
	int m_positionX;
	int m_positionY;
};