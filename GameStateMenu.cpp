#include "GameStateMenu.h"
#include "GameStatePlay.h"
#include "GameState.h"

GameStateMenu::GameStateMenu(Game* game) 
{
	this->game = game; 

	createTitle();

	buttons[0] = MenuButton("Play", Data::font, sf::Vector2f(Config::windowSize.x / 2.0f, 180.0f));
	buttons[1] = MenuButton("Exit", Data::font, sf::Vector2f(Config::windowSize.x / 2.0f, 280.0f));
}

void GameStateMenu::createTitle()
{		
	title.setFont(Data::font);
	title.setString("Tic Tac Toe");
	title.setCharacterSize(65);
	title.setStyle(sf::Text::Style::Bold);
	title.setFillColor(Color::Green);
	title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	title.setPosition(Config::windowSize.x / 2.0f, 50.0f);
}

void GameStateMenu::playGame()
{
	game->pushState(new GameStatePlay(game));
}

void GameStateMenu::draw()
{
	game->window.clear(Color::Grey);
	game->window.draw(title);

	for (auto & button : buttons)
	{
		game->window.draw(button);
	}		

	game->window.display();
}

void GameStateMenu::update()
{
	for (auto & button : buttons)
	{
		button.update(game->mousePosition);
	}		
}

void GameStateMenu::handleInput()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{		
		switch (event.type)
		{
		case sf::Event::Closed:		
			game->window.close();
			break;		
		case sf::Event::KeyPressed:		
			if (event.key.code == sf::Keyboard::Escape)
			{
				game->window.close();
			}				
			break;		
		case sf::Event::MouseButtonPressed:		
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				for (auto & button : buttons)
				{
					if (button.isHover(game->mousePosition) && button.getString() == "Play")
					{
						playGame();
					}						
					else if (button.isHover(game->mousePosition) && button.getString() == "Exit")
					{
						game->window.close();
					}						
				}							
		}
		default:
			break;
		}
	}

	return;
}
