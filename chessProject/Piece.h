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
	virtual bool mov(string command, Piece* (&board)[8][8]);
	virtual bool isPieceInWay(string command, Piece* (&board)[8][8], int row, int col,
		int destRow, int destCol);
	virtual bool isCheck(Piece* (&board)[8][8], int destRow, int destCol);
	void setName(char c);
	void setPosition(string position);
	void setColor(char c);
	char getName();
	char getColor();
	string getPosition();
private:
	char _name;
	char _color;
	string _position;
};