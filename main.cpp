#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Camera.h"
#include "Renderer.h"

int main()
{
   sf::RenderWindow window(sf::VideoMode(1200, 900), "BETTER Mario");
   sf::Clock deltaClock;
   Renderer renderer(window);

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

	   window.clear(sf::Color(20, 20, 20));
	   Render(renderer);
	   window.display();	  
   }
}
