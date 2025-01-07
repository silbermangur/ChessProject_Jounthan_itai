#pragma once
#include <string>

class Piece
{
public:
	Piece(char name, int color);
    ~Piece();
	virtual bool move(int command[], bool isFirstTurn) = 0;
	char getName();
	int getColor();
	
private:
	char _name;
	int _color;


};