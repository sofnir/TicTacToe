#pragma once
#include "TextButton.h"
#include <array>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RectangleShape.hpp>

class BottomMenu : public sf::Drawable
{
public:
	BottomMenu();

	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void update(const sf::Vector2f & mousePosition);	
	bool isBackHover(const sf::Vector2f & mousePosition);
	bool isPlayAgainHover(const sf::Vector2f & mousePosition);

private:	
	TextButton buttons[2];
	sf::RectangleShape background;

	void createButtons();
	void createBackground();
};
