#pragma once

#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera(float zoomLevel = 5.0f);
	sf::View getView(sf::Vector2u windowSize) const;
private:
	float zoomLevel;
};

