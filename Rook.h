#pragma once
#include "Piece.h"

class Rook : public Piece 
{
public:
	Rook(char name, char color, std::string position);
	virtual bool move(Piece* (&board)[8][8], int row, int col, int destRow, int destCol) override;
	virtual bool isPieceInWay(Piece* (&board)[8][8], int row, int col,
		int destRow, int destCol) override;
};