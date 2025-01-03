#pragma once
#include "Piece.h"

class Knight : public Piece {
	virtual bool move(int command[], bool isFirstTurn);
};