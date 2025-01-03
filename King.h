#pragma once
#include "Piece.h"

class King : public Piece {
	virtual bool move(int command[], bool isFirstTurn);
};