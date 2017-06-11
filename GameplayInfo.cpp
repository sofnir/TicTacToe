#include "GameplayInfo.h"

GameplayInfo::GameplayInfo()
{	
	createBackground();
	createPoints();
}

GameplayInfo::~GameplayInfo()
{
	;
}

void GameplayInfo::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(background);

	for (auto & point: points)
		target.draw(point);
}

void GameplayInfo::update(const Logic & logic)
{
	const sf::String playersStr[2] = { "O  :  " + std::to_string(logic.getPoints()[0]), 
		"X  :  " + std::to_string(logic.getPoints()[1]) };
	
	for (int i = 0; i < 2; i++)
	{
		points[i].setString(playersStr[i]);
		points[i].setOrigin(sf::Vector2f(points[i].getGlobalBounds().width / 2.0f, points[i].getGlobalBounds().height / 2.0f));
		points[i].setPosition(sf::Vector2f(Config::windowSize.x / 4.0f + (Config::windowSize.x / 2.0f) * i, 20.0f));
	}
}

void GameplayInfo::createBackground()
{
	background.setSize(sf::Vector2f(Config::windowSize.x, 60));
	background.setFillColor(Color::Green);
}

void GameplayInfo::createPoints()
{
	const sf::String playersStr[2] = { "O  :  0" + 0, "X  :  0" + 0 };

	for (int i = 0; i < 2; i++)
	{
		points[i].setFont(Data::font);
		points[i].setStyle(sf::Text::Style::Bold);
		points[i].setString(playersStr[i]);
		points[i].setCharacterSize(30);
		points[i].setOrigin(sf::Vector2f(points[i].getGlobalBounds().width / 2.0f, points[i].getGlobalBounds().height / 2.0f));
		points[i].setPosition(sf::Vector2f(Config::windowSize.x / 4.0f + (Config::windowSize.x / 2.0f) * i, 20.0f));
	}	
}
