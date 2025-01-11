#include "Piece.h"

bool Piece::mov(int srcRow, int srcCol, int dstRow, int dstCol,  Piece* (&board)[8][8])
{
	return false;
}

bool Piece::isPieceInWay(Piece* (&board)[8][8], int row, int col,
	int destRow, int destCol)
{
	return 0;
}
void Piece::setName(char c)
{
	this->_name = c;
}

void Piece::setPosition(string position)
{
	this->_position = position;
}

void Piece::setColor(char c)
{
	this->_color = c;
}

char Piece::getName() const
{
	return this->_name;
}

char Piece::getColor() const
{
	return this->_color;
}

string Piece::getPosition() const
{
	return this->_position;
}
