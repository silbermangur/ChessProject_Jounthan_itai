#include "Piece.h"

Piece::~Piece()
{
	_name = '#';
	_color = '#';
}

bool Piece::move(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
	return false;
}

bool Piece::isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
	return false;
}

char Piece::getName()
{
	return _name;
}

char Piece::getColor()
{
	return _color;
}

std::string Piece::getPosition() const
{
	return _position;
}

void Piece::setName(char name)
{
	_name = name;
}

void Piece::setColor(char color)
{
	_color = color;
}

void Piece::setPosition(std::string position)
{
	_position = position;
}
