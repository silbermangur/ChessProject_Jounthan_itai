#pragma once
#include <string>
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include <vector>
using namespace std;


class GameManager 
{
public:
	GameManager(string gameBoard);
	void boardInit(std::string board);
	void initPieceInBoard(char name, int height, int width, string position);
	~GameManager();
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
	Piece* _board[8][8] = {nullptr};
	vector<vector<string>> positionBoard;
	char _turn;
	int turnCounter = 0;
};