#include "Piece.h"




bool Piece::mov(string command,  Piece* (&board)[8][8])
{
	return false;
}

bool Piece::isPieceInWay(string command, Piece* (&board)[8][8], int row, int col,
	int destRow, int destCol)
{
	return false;
}

bool Piece::isCheck(Piece* (&board)[8][8], int destRow, int destCol)
{
	return false;
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

char Piece::getName()
{
	return this->_name;
}

char Piece::getColor()
{
	return this->_color;
}

string Piece::getPosition()
{
	return this->_position;
}
