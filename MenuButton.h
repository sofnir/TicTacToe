#pragma once
#include "TextButton.h"
#include "SFML\Graphics\RectangleShape.hpp"

class MenuButton : public sf::Drawable
{
public:
	MenuButton();
	MenuButton(const sf::String & string, const sf::Font & font, const sf::Vector2f & position);

	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	
	void update(const sf::Vector2f &mousePosition) { textButton.update(mousePosition); }
	bool isHover(const sf::Vector2f &mousePosition) const { return textButton.isHover(mousePosition); }
	const sf::String & getString() const { return textButton.getString(); }

private:
	TextButton textButton;
	sf::RectangleShape background;

	void createTextButton(const sf::String & string, const sf::Font & font, const sf::Vector2f & position);
	void createBackground();
};