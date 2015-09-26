#include <string>
#include <SFML/Graphics.hpp>

class Bubble :public sf::CircleShape
{
public:
	Bubble();
	~Bubble();
	void Move(float mouseX, float mouseY);
	sf::Vector2f getCenter();
	int getSize();
	void Eat(int size);

private:
	int m_size;
	int m_speed;
	int m_currentX;
	int m_currentY;
	std::string m_color;
	int m_positionX;
	int m_positionY;
};