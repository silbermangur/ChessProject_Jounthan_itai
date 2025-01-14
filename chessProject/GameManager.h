#pragma once
#include "Rock.h"
#include "Piece.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"
#include <vector>


class GameManger 
{
public:
	GameManger(string gameBoard);
	~GameManger();
	void printBoard();
	void printPosition();

	int isCommandValid(string command);
	bool doesMovePutKingInCheck(int srcRow, int srcCol
		, int destRow, int destCol, Piece* (&board)[8][8], string command);
	bool didMoveCheckOpponent(int srcRow, int srcCol, Piece* (&board)[8][8], string command);
	


	void printColor();
	void movePiece(int srcRow, int srcCol, int destRow, int destCol, string srcSquare, string dstSquare);
	vector<vector<string>> getPositionBoard();

private:
	Piece* board[8][8] = {nullptr};
	vector<vector<string>> positionBoard;
	char turn = 'b';
	int turnCounter = 0;
};