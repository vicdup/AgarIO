#include <vector>
#include <SFML/Graphics.hpp>
#include "Food.h"
#include "Bubble.h"

using namespace std;
const int worldSize = 2000;
const int initialFood = 100;

bool checkCollision(Bubble bubble, Food food)
{
	if (sqrt((bubble.getCenter().x - food.getCenter().x)*(bubble.getCenter().x - food.getCenter().x)
		+ (bubble.getCenter().y - food.getCenter().y)*(bubble.getCenter().y - food.getCenter().y))
		< abs(bubble.getSize()-food.getSize()/2))
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
	// création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(800, 800), "Agar");
	window.setFramerateLimit(30);
	sf::View view(sf::Vector2f(300, 300), sf::Vector2f(800, 800));

	//chrono
	sf::Clock clock;
	vector<Food> lFood;
	vector<Bubble> lBubble;
	Bubble bubble;
	lBubble.push_back(bubble);

	int foodGenerated = 0;

	for (int i(0); i <initialFood; ++i)
	{
		Food food;
		lFood.push_back(food);
	}

	// on fait tourner le programme tant que la fenêtre n'a pas été fermée
	while (window.isOpen())
	{
		// on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
		sf::Event event;
		while (window.pollEvent(event))
		{
			// on regarde le type de l'évènement...
			switch (event.type)
			{
				// fenêtre fermée
			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}
		}

		window.clear(sf::Color::White);
		if (static_cast<int>(clock.getElapsedTime().asSeconds()) % 2 == 1)
		{
			foodGenerated = 0;
		}
		if (static_cast<int>(clock.getElapsedTime().asSeconds())%2==0 && foodGenerated ==0)
		{
			Food food;
			lFood.push_back(food);
			foodGenerated = 1;
		}

		for (int i(0); i < lFood.size(); ++i)
		{
			window.draw(lFood[i]);
		}
		for (int i(0); i < lBubble.size(); ++i)
		{
			view.setCenter(lBubble[i].getCenter());
			window.draw(lBubble[i]);
			float mouseX = static_cast<float>(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x);
			float mouseY = static_cast<float>(window.mapPixelToCoords(sf::Mouse::getPosition(window)).y);
			lBubble[i].Move(mouseX, mouseY);

			for (int u(0); u < lFood.size(); ++u)
			{
				if (checkCollision(lBubble[i], lFood[u]))
				{
					lBubble[i].Eat(lFood[u].getSize());
					lFood.erase(lFood.begin()+ u);

				}
				else
				{
					window.draw(lFood[u]);
				}
			}
		}
		window.display();
		window.setView(view);
	}

	return 0;
}

