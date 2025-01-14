#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(char name, char color, string position, bool hasMoved) : Piece(name, color, position), hasMoved(hasMoved) {};
	bool mov(int srcRow, int srcCol, int dstRow, int dstCol, Piece* (&board)[8][8]) override;
	bool isPieceInWay(Piece* (&board)[8][8], int row, int col,
		int destRow, int destCol) override;
	void setHasMoved();
private:
	bool hasMoved = false;
};