#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Piece
{
public:
	Piece(char name = ' ', char color = ' ', string position = "")
		: _name(name), _color(color), _position(position) {}
    ~Piece();
	virtual bool move(Piece* (&board)[8][8], int row, int col, int destRow, int destCol);
	virtual bool isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol);
	char getName();
	char getColor();
	string getPosition()const;
	void setName(char name);
	void setColor(char color);
	void setPosition(string position);
	
private:
	char _name;
	char _color;
	string _position;

};