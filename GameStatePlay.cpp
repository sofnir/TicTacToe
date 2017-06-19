#include "GameStatePlay.h"
#include "GameState.h"

GameStatePlay::GameStatePlay(Game * game)
{
	this->game = game;
}

void GameStatePlay::draw()
{
	game->window.clear(Color::Grey);
	game->window.draw(bottomMenu);
	game->window.draw(gameplayInfo);
	game->window.draw(board);
	game->window.display();
}

void GameStatePlay::update()
{
	bottomMenu.update(game->mousePosition);
}

void GameStatePlay::handleInput()
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
				game->popState();
				return;
			}
			break;		
		case sf::Event::MouseButtonPressed:		
			if (event.mouseButton.button == sf::Mouse::Left)
			{				
				if(bottomMenu.isBackHover(game->mousePosition))				
				{
					game->popState();
					return;
				}
				if (bottomMenu.isPlayAgainHover(game->mousePosition))
				{				
					board.reset();
					logic.setPlayingState();
				}
				
				for (int y = 0; y < 3; y++)
				{
					for (int x = 0; x < 3; x++)
					{
						if (board.isFieldHover(x, y, game->mousePosition) && board.isFieldEmpty(x, y) &&
							logic.getState() == Logic::State::PLAYING)
						{
							board.push(x, y, logic.getTurn());
							logic.checkSituation(board);

							if (logic.getState() != Logic::State::PLAYING)
							{
								logic.updatePoints();
								gameplayInfo.update(logic);
							}

							logic.changeTurn();
						}
					}
				}					
			}		
		default: break;
		}
	}

	return;
}
