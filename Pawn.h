#pragma once
#include "Piece.h"

class Pawn : public Piece {
	virtual bool move(int command[], bool isFirstTurn);
};