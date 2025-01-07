#pragma once
#include "Piece.h"

class Queen : public Piece {
	virtual bool move(int command[], bool isFirstTurn);
};