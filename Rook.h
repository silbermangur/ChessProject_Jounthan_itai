#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
	Rook(char name, char color);
	virtual bool move(Piece* (&board)[8][8], int command[]) override;
	virtual  bool isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol) override;
};
