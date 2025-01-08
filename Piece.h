#pragma once
#include <string>

class Piece
{
public:
	Piece(char name, char color);
    ~Piece();
	virtual bool move(Piece* (&board)[8][8], int command[]) = 0;
	virtual bool isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol) = 0;
	char getName();
	char getColor();
	void setName(char name);
	void setColor(char color);
	
private:
	char _name;
	char _color;

};