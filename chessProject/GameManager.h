#pragma once
#include "Rock.h"
#include "Piece.h"
#include <vector>


class GameManger 
{
public:
	GameManger(string gameBoard);
	~GameManger();
	void printBoard();
	void printPosition();

	int isCommandValid(string command);
	


	void printColor();
	bool setBoard(string command);
	void movePiece(string dest, int row, int col);
	vector<vector<string>> getPositionBoard();

private:
	Piece* board[8][8] = {nullptr};
	vector<vector<string>> positionBoard;
	char turn = 'b';
	int turnCounter = 0;
};