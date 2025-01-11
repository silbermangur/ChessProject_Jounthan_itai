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
	virtual ~Piece() {}
	virtual bool mov(int srcRow, int srcCol, int dstRow, int dstCol, Piece* (&board)[8][8]);
	virtual bool isPieceInWay(Piece* (&board)[8][8], int row, int col,
		int destRow, int destCol);
	void setName(char c);
	void setPosition(string position);
	void setColor(char c);

	char getName() const;
	char getColor() const;
	string getPosition()const;
private:
	char _name;
	char _color;
	string _position;
};