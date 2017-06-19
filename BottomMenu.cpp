#include "BottomMenu.h"

BottomMenu::BottomMenu()
{
	createButtons();
	createBackground();
}

void BottomMenu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(background);

	for (auto & button : buttons)
	{
		target.draw(button);
	}		
}

void BottomMenu::update(const sf::Vector2f & mousePosition)
{
	for (auto & button : buttons)
	{
		button.update(mousePosition);
	}		
}

bool BottomMenu::isBackHover(const sf::Vector2f & mousePosition)
{
	return buttons[0].isHover(mousePosition);
}

bool BottomMenu::isPlayAgainHover(const sf::Vector2f & mousePosition)
{
	return buttons[1].isHover(mousePosition);
}

void BottomMenu::createButtons()
{
	buttons[0] = TextButton("Back", Data::font, 30);
	buttons[1] = TextButton("Play again", Data::font, 30);
	
	for(int i = 0; i < 2; i++)
	{
		buttons[i].setHoverColor(Color::Grey);
		buttons[i].setFillColor(sf::Color::White);		
		buttons[i].setStyle(sf::Text::Style::Bold);		
		buttons[i].setOrigin(sf::Vector2f(buttons[i].getGlobalBounds().width / 2.0f, 
			buttons[i].getGlobalBounds().height / 2.0f));
		buttons[i].setPosition(sf::Vector2f(Config::windowSize.x / 4.0f + Config::windowSize.x / 2.0f * i, 
			Config::windowSize.y - 37.0f));
	}	
}

void BottomMenu::createBackground()
{
	background.setSize(sf::Vector2f(Config::windowSize.x, 60));
	background.setFillColor(Color::Green);
	background.setPosition(sf::Vector2f(0, Config::windowSize.y - background.getSize().y));
}
