#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(char name, char color, string position) : Piece(name, color, position) {};
	bool mov(int srcRow, int srcCol, int dstRow, int dstCol, Piece* (&board)[8][8]) override;
	bool isPieceInWay(Piece* (&board)[8][8], int row, int col,
		int destRow, int destCol) override;
};