#pragma once
#include "TextButton.h"
#include <array>

class BottomMenu : public sf::Drawable
{
public:
	BottomMenu();
	~BottomMenu();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void update(const sf::Vector2f & mousePosition);	
	bool isBackHover(const sf::Vector2f & mousePosition);
	bool isPlayAgainHover(const sf::Vector2f & mousePosition);

private:	
	TextButton buttons[2];
	sf::RectangleShape background;

	void createButtons();
	void createBackground();
};
