#include "Piece.h"

Piece::Piece(char name, char color)
{
	setName(name);
	setColor(color);
}

Piece::~Piece()
{
	_name = '#';
	_color = '#';
}

char Piece::getName()
{
	return _name;
}

char Piece::getColor()
{
	return _color;
}

int* Piece::getPosition()
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

