#include "Board.h"

Board::Board()
{
	createLines();

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			fields[y][x] = Field(Data::font, sf::Vector2f((Config::windowSize.x - 246.0f) / 2.0f + (83.0f) * x,
				(Config::windowSize.y - 246.0f) / 2.0f + (83.0f) * y));
		}
	}
}

Board::~Board()
{
	;
}

void Board::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto & line : lines)
		target.draw(line);

	for (auto & row : fields)
		for (auto & field : row)
			target.draw(field);
}

bool Board::isFieldHover(int x, int y, const sf::Vector2f & mousePosition) const
{
	return fields[y][x].isHover(mousePosition);
}

bool Board::isFieldEmpty(int x, int y) const
{
	return fields[y][x].isEmpty();
}

const sf::String & Board::getFieldString(int x, int y) const
{
	return fields[y][x].getString();
}

void Board::push(int x, int y, const sf::String & string)
{
	fields[y][x].setString(string);
}

void Board::reset()
{
	for (auto & row : fields)
		for (auto & field : row)
			field.setString(" ");
}

void Board::createLines()
{
	for (int i = 0; i < 4; i++)
	{
		lines[i].setFillColor(Color::Green);

		if (i < 2)
		{
			lines[i].setSize(sf::Vector2f(3, 246));
			lines[i].setPosition(sf::Vector2f(Config::windowSize.x / 2.0f - 80.0f / 2.0f - lines[i].getSize().x + 83.0f * i,
				Config::windowSize.y / 2.0f - lines[i].getSize().y / 2.0f));
		}
		else
		{
			lines[i].setSize(sf::Vector2f(246, 3));
			lines[i].setPosition(sf::Vector2f(Config::windowSize.x / 2.0f - lines[i].getSize().x / 2.0f, 
				Config::windowSize.y / 2.0f - 80.0f / 2.0f - lines[i].getSize().y + 83.0f * (i - 2.0f)));
		}
	}
}
