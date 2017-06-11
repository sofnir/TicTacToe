#include "MenuButton.h"

MenuButton::MenuButton()
{
	;
}

MenuButton::MenuButton(const sf::String & string, const sf::Font & font, const sf::Vector2f & position)
{
	createTextButton(string, font, position);
	createBackground();
}

MenuButton::~MenuButton()
{
	;
}

void MenuButton::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(background);
	target.draw(textButton);
}

void MenuButton::createTextButton(const sf::String & string, const sf::Font & font, const sf::Vector2f & position)
{
	textButton.setFillColor(sf::Color::White);
	textButton.setHoverColor(Color::Grey);
	textButton.setString(string);
	textButton.setFont(font);
	textButton.setCharacterSize(40);
	textButton.setStyle(sf::Text::Style::Bold);
	textButton.setOrigin(textButton.getGlobalBounds().width / 2, textButton.getGlobalBounds().height / 2);
	textButton.setPosition(position);
}
//320.0f, 180.0f + index * 100.0f)

void MenuButton::createBackground()
{
	background.setSize(sf::Vector2f(Config::windowSize.x, textButton.getGlobalBounds().height + 20.0f));
	background.setPosition(sf::Vector2f(0, textButton.getGlobalBounds().top - 10));
	background.setFillColor(Color::Green);
}
