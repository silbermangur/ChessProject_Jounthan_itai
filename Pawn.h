#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
	Pawn(char name, char color);
	virtual bool move(Piece* (&board)[8][8], int command[]) override;
	virtual bool isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol) override;
};