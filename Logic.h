#pragma once
#include "Board.h"

class Logic
{
public:
	Logic();

	enum class State { PLAYING, O_WIN, X_WIN, DRAW };

	const sf::String & getTurn() const { return turn; }
	const State & getState() const { return state; }
	const int * getPoints() const { return points; }
	void changeTurn() { turn = (turn == "o") ? "x" : "o"; }
	void checkSituation(Board & board);
	void setPlayingState() { state = State::PLAYING; }
	void updatePoints();

private:
	sf::String turn = "o";	
	State state = State::PLAYING;
	int points[2] = { 0 }; // o = 0, x = 1
};
