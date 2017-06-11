#pragma once
#include "SFML\Graphics.hpp"
#include "Board.h"
#include <iostream>

class Logic
{
public:
	Logic();
	~Logic();

	enum State { PLAYING, O_WIN, X_WIN, DRAW };

	const sf::String & getTurn() const { return turn; }
	const State & getState() const { return state; }
	const int * getPoints() const { return points; }
	void changeTurn() { turn = (turn == "o") ? "x" : "o"; }
	void checkSituation(Board & board);
	void setPlayingState() { state = PLAYING; }
	void updatePoints();

private:
	sf::String turn = "o";	
	State state = PLAYING;
	int points[2] = { 0 }; // o = 0, x = 1
};
