#include "Piece.h"

Piece::Piece(char name, int color)
{
	_name = name;
	_color = color;
}

Piece::~Piece()
{
	_name = '#';
}

char Piece::getName()
{
	return _name;
}

int Piece::getColor()
{
	return _color;
}

