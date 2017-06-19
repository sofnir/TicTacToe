#include "Field.h"

Field::Field()
{
	;
}

Field::Field(const sf::Font & font, const sf::Vector2f & position)
{
	createBackground(position);
	createText(font);
}

void Field::draw(sf::RenderTarget & target, sf::RenderStates states) const 
{
	target.draw(background);
	target.draw(text);
}

bool Field::isHover(const sf::Vector2f & mousePosition) const
{
	return (background.getGlobalBounds().contains(mousePosition));
}

bool Field::isEmpty() const
{
	return text.getString() == " ";
}

const sf::String & Field::getString() const
{
	return text.getString();
}

void Field::createBackground(const sf::Vector2f & position)
{
	background.setSize(sf::Vector2f(80, 80));
	background.setFillColor(sf::Color::Transparent);
	background.setPosition(position);
}

void Field::createText(const sf::Font & font)
{
	text.setFont(font);
	text.setString(" ");
	text.setCharacterSize(70);
	text.setPosition(background.getPosition().x + background.getSize().x / 4.0f,
		background.getPosition().y - background.getSize().y / 6.0f);
}
