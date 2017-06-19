#pragma once
#include "Data.h"
#include "Logic.h"
#include <SFML\Graphics\Text.hpp>

class GameplayInfo : public sf::Drawable
{
public:
	GameplayInfo();

	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void update(const Logic & logic);

private:
	sf::RectangleShape background;
	sf::Text points[2];

	void createBackground();
	void createPoints();
};

