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
	void initPieceInBoard(char name, int height, int width);
	~GameManager();
	void printBoard();
	void printPosition();

	int isCommandValid(string command);
	


	void printColor();
	bool setBoard(string command);
	void movePiece(string dest, int row, int col);
	vector<vector<string>> getPositionBoard();

private:
	Piece* _board[8][8];
	char _turn;
	vector<vector<string>> positionBoard;
};