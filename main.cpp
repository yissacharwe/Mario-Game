#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Camera.h"

int main()
{
   sf::RenderWindow window(sf::VideoMode(1200, 900), "BETTER Mario");
   sf::Clock deltaClock;
   Camera camera;

   Begin(window);
   while (window.isOpen())
   {
	   float deltaTime = deltaClock.restart().asSeconds();

	   sf::Event event{};
	   while (window.pollEvent(event))
	   {
		   if (event.type == sf::Event::Closed)
			   window.close();
	   }

	   window.setView(camera.getView(window.getSize()));
	   Update(deltaTime);

	   window.clear();
	   
	   Render(window);

	   window.display();
   }
}
