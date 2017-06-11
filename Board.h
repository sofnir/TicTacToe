#pragma once
#include "SFML\Graphics.hpp"
#include "Data.h"
#include "Field.h"

class Board : public sf::Drawable
{
public:
	Board();
	~Board();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	bool isFieldHover(int x, int y, const sf::Vector2f & mousePosition) const;
	bool isFieldEmpty(int x, int y) const;
	const sf::String & getFieldString(int x, int y) const;
	void push(int x, int y, const sf::String & string);
	void reset();

private:
	sf::RectangleShape lines[4];
	Field fields[3][3];

	void createLines();
};

