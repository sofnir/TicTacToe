#pragma once
#include <SFML\Graphics.hpp>
#include "Data.h"

class Field : public sf::Drawable
{
public:
	Field();
	Field(const sf::Font & font, const sf::Vector2f & position);
	~Field();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	bool isHover(const sf::Vector2f & mousePosition) const;
	void setString(const sf::String & string) { text.setString(string); }
	bool isEmpty() const;
	const sf::String & getString() const;

private:
	sf::RectangleShape background;
	sf::Text text;

	void createBackground(const sf::Vector2f & position);
	void createText(const sf::Font & font);
};
