#pragma once
#include "Piece.h"

class Rock : public Piece 
{
public:
	Rock(char name, char color, string position) : Piece(name, color, position) {};
	bool mov(string command, Piece* (&board)[8][8]) override;
	bool isPieceInWay(string command, Piece* (&board)[8][8], int row, int col,
		int destRow, int destCol) override;
	bool isCheck(Piece* (&board)[8][8], int destRow, int destCol) override;
};