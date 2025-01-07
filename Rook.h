#pragma once
#include "Piece.h"

class Rook : public Piece {
	virtual bool move(int command[], bool isFirstTurn);
};
