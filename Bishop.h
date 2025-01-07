#pragma once
#include "Piece.h"

class Bishop : public Piece {
	virtual bool move(int command[], bool isFirstTurn);
};
