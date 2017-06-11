#pragma once
#include <SFML\Graphics.hpp>
#include "Data.h"
#include "Logic.h"

class GameplayInfo : public sf::Drawable
{
public:
	GameplayInfo();
	~GameplayInfo();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void update(const Logic & logic);

private:
	sf::RectangleShape background;
	sf::Text points[2];

	void createBackground();
	void createPoints();
};

