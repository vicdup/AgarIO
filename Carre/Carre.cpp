#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Bubble.h"
#include "Global.h"

int worldSize = 2000;
int initialFood = 100;
using namespace std;
//test

bool checkCollision(Entity bubble, Entity entity)
{
	if (sqrt((bubble.getCenter().x - entity.getCenter().x)*(bubble.getCenter().x - entity.getCenter().x)
		+ (bubble.getCenter().y - entity.getCenter().y)*(bubble.getCenter().y - entity.getCenter().y))
		< abs(bubble.getSize()-entity.getSize()/2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	// cr�ation de la fen�tre
	sf::RenderWindow window(sf::VideoMode(800, 800), "Agar");
	window.setFramerateLimit(30);
	sf::View view(sf::Vector2f(300, 300), sf::Vector2f(800, 800));


	//chrono
	sf::Clock clock;
	vector<Entity> lEntity;
	vector<Bubble> lBubble;
	Bubble bubble;
	lBubble.push_back(bubble);

	int entityGenerated = 0;

	for (int i(0); i < initialFood; ++i)
	{
		Entity entity;
		lEntity.push_back(entity);
	}

	// on fait tourner le programme tant que la fen�tre n'a pas �t� ferm�e
	while (window.isOpen())
	{
		// on traite tous les �v�nements de la fen�tre qui ont �t� g�n�r�s depuis la derni�re it�ration de la boucle
		sf::Event event;
		while (window.pollEvent(event))
		{
			// on regarde le type de l'�v�nement...
			switch (event.type)
			{
				// fen�tre ferm�e
			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}
		}

		window.clear(sf::Color::White);
		if (static_cast<int>(clock.getElapsedTime().asSeconds()) % 3 == 1)
		{
			entityGenerated = 0;
		}
		if (static_cast<int>(clock.getElapsedTime().asSeconds())%3==0 && entityGenerated ==0)
		{
			Entity entity;
			lEntity.push_back(entity);
			entityGenerated = 1;
		}

		for (int i(0); i < lEntity.size(); ++i)
		{
			window.draw(lEntity[i]);
		}
		for (int i(0); i < lBubble.size(); ++i)
		{
			view.setCenter(lBubble[i].getCenter());
			window.draw(lBubble[i]);
			float mouseX = static_cast<float>(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x);
			float mouseY = static_cast<float>(window.mapPixelToCoords(sf::Mouse::getPosition(window)).y);
			lBubble[i].Move(mouseX, mouseY);

			for (int u(0); u < lEntity.size(); ++u)
			{
				if (checkCollision(lBubble[i], lEntity[u]))
				{
					lBubble[i].Eat(lEntity[u].getSize());
					lEntity.erase(lEntity.begin()+ u);

				}
				else
				{
					window.draw(lEntity[u]);
				}
			}
		}
		window.display();
		window.setView(view);
	}

	return 0;
}

