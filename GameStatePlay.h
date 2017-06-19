#pragma once
#include "GameState.h"
#include "BottomMenu.h"
#include "GameplayInfo.h"
#include "Board.h"
#include "Logic.h"
#include <SFML\Window\Event.hpp>

class GameStatePlay : public GameState
{
public:
	GameStatePlay(Game * game);

	void draw() override;
	void update() override;
	void handleInput() override;

private:	
	BottomMenu bottomMenu;
	GameplayInfo gameplayInfo;
	Board board;
	Logic logic;
};
