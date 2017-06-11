#include "Logic.h"

Logic::Logic()
{
	;
}

Logic::~Logic()
{
	;
}

void Logic::checkSituation(Board & board)
{
	unsigned busy = 0;

	//vertical checikng
	for (int x = 0; x < 3; x++)
	{
		if (!board.isFieldEmpty(x, 0) && board.getFieldString(x, 0) == board.getFieldString(x, 1)
			&& board.getFieldString(x, 0) == board.getFieldString(x, 2))
		{
			state = (turn == "o") ? O_WIN : X_WIN;
			return;
		}
	}
	
	//horizontal checking
	for (int y = 0; y < 3; y++)
	{
		if (!board.isFieldEmpty(0, y) && board.getFieldString(0, y) == board.getFieldString(1, y)
			&& board.getFieldString(0, y) == board.getFieldString(2, y))
		{
			state = (turn == "o") ? O_WIN : X_WIN;
			return;
		}
	}
	
	// Cross checking
	if (!board.isFieldEmpty(0, 0) && board.getFieldString(0, 0) == board.getFieldString(1, 1)
		&& board.getFieldString(0, 0) == board.getFieldString(2, 2))
	{
		state = (turn == "o") ? O_WIN : X_WIN;
		return;
	}

	if (!board.isFieldEmpty(0, 2) && board.getFieldString(0, 2) == board.getFieldString(1, 1)
		&& board.getFieldString(0, 2) == board.getFieldString(2, 0))
	{
		state = (turn == "o") ? O_WIN : X_WIN;
		return;
	}

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (!board.isFieldEmpty(x, y))
				busy++;
		}
	}

	if (busy == 9)
		state = DRAW;
}

void Logic::updatePoints()
{
	if (state == O_WIN)
		points[0]++;
	else if (state == X_WIN)
		points[1]++;
}
