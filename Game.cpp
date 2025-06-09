#include "Game.h"
#include "Resources.h"
#include "Map.h"
#include "Camera.h"

#include <filesystem>
#include <iostream>

Map map(16.0f);
Camera camera(320.0f);

const float movementSpeed = 100.08;

void Begin(const sf::Window& window)
{
	for (auto& file : std::filesystem::directory_iterator("./resources/textures/"))
	{
		if (file.is_regular_file() && (file.path().extension() == ".png" ||
			file.path().extension() == ".jpg"))
		{
			Resources::textures[file.path().filename().string()].loadFromFile(
				file.path().string());
		}
	}

	sf::Image image;
    image.loadFromFile("resources/map.png");  
	map.CreateFromImage(image);

	camera.position = sf::Vector2f(160.0f, 160.0f);
}

void Update(float deltaTime)
{
	float move = movementSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		move *= 2;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		camera.position.x += move * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		camera.position.y -= move * deltaTime;
}

void Render(Renderer& renderer)
{
	map.Draw(renderer);
}