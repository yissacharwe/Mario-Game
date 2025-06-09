// Camera.h : manages the view position and zoom level for rendering scenes.
#pragma once
#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera(float zoomLevel = 5.0f);
	sf::View getView(sf::Vector2u windowSize) const;
	sf::Vector2f position;
private:
	float zoomLevel;
};

