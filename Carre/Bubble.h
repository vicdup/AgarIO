#include <string>
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Bubble :public Entity
{
public:
	Bubble();
	~Bubble();
	void Move(float mouseX, float mouseY);
	void Eat(float size);

private:
	float m_speed;
};