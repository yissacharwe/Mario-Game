#include "Camera.h"

Camera::Camera(float zoomLevel)
	: zoomLevel(zoomLevel)
{
}

// Calculate the size of the view based on the zoom level and aspect ratio
sf::View Camera::getView(sf::Vector2u windowSize) const
{
	float aspect = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);
	sf::Vector2f size;

	// Adjust the size based on the aspect ratio
	if (aspect < 1.0f)
		// window is taller than it is wide
		size = sf::Vector2f(zoomLevel, zoomLevel / aspect);
	else
		// window is wider than it is tall
		size = sf::Vector2f(zoomLevel * aspect, zoomLevel);

	// return the view centered at (0, 0) with the calculated size
	return sf::View(sf::Vector2f(0, 0), size);
}