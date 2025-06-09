#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Renderer.h"


class Map
{
public:
	Map(float cellSize = 32.0f);
	void CreateCheckerboard(size_t width, size_t height);
	void CreateFromImage(const sf::Image& image);

	void Draw(Renderer& renderer);

	std::vector<std::vector<int>> grid;
	float cellSize;
};

