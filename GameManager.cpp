#include "GameManager.h"
#include <iostream>

GameManager::GameManager(string gameBoard) : positionBoard(8, vector<string>(8))
{
	if (gameBoard[64] == '0')
	{
		_turn = 'w';
	}
	else
	{
		_turn = 'b';
	}
	boardInit(gameBoard);
}

void GameManager::boardInit(std::string board)
{
	string pos  = {0};
	int i, j, curChar = 0;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			pos[0] = (j + '0') + 48;
			pos[1] = (i + '0');
			initPieceInBoard(board[curChar], i, j, pos);
			curChar++;
		}
	}
}

void GameManager::initPieceInBoard(char name, int height, int width, string position)
{
	_board[height][width] = nullptr;

	switch (name)
	{
	case '#':
		_board[height][width] = new Piece(name, name, position);
		break;
	case 'K':
		_board[height][width] = new King(name, 'w', position);
		break;
	case 'k':
		_board[height][width] = new King(name, 'b', position);
		break;
	case 'Q':
		_board[height][width] = new Queen(name, 'w', position);
		break;
	case 'q':
		_board[height][width] = new Queen(name, 'b', position);
		break;
	case 'R':
		_board[height][width] = new Rook(name, 'w', position);
		break;
	case 'r':
		_board[height][width] = new Rook(name, 'b', position);
		break;
	case 'N':
		_board[height][width] = new Knight(name, 'w', position);
		break;
	case 'n':
		_board[height][width] = new Knight(name, 'b', position);
		break;
	case 'B':
		_board[height][width] = new Bishop(name, 'w', position);
		break;
	case 'b':
		_board[height][width] = new Bishop(name, 'b', position);
		break;
	case 'P':
		_board[height][width] = new Pawn(name, 'w', position);
		break;
	case 'p':
		_board[height][width] = new Pawn(name, 'b', position);
		break;
	}
}

GameManager::~GameManager()
{
	for (int i = 0; i < 8; ++i) 
	{
		for (int j = 0; j < 8; ++j) 
		{
			delete _board[i][j];  // Delete the Piece (or derived object) pointed to by board[i][j]
		}
	}
}

void GameManager::printBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << _board[i][j]->getName();
			cout << ' ';
		}
		cout << "\n";
	}
}

void GameManager::printPosition()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << this->positionBoard[i][j];
			cout << ' ';
		}
		cout << "\n";
	}
}

int GameManager::isCommandValid(string command)
{
	int destRow = command[3] - '0' - 1;  // '1' -> row 0, '2' -> row 1, etc.
	int destCol = command[2] - 'a';  // 'a' -> column 0, 'b' -> column 1, etc.
	int row = command[1] - '0' - 1;  // '1' -> row 0, '2' -> row 1, etc.
	int col = command[0] - 'a';// 'a' -> column 0, 'b' -> column 1, etc.
	string srcSquare = command.substr(0, 2);
	string dstSquare = command.substr(2, 2);


	if (command[0] == command[2] && command[1] == command[3])
	{
		cout << "Invalid Move!!source square and dest square identical." << endl;
		return 7;
	}
	else if (command[0] > 'h' || command[0] < 'a' || command[2] > 'h' || command[2] < 'a'
		|| command[1] < '1' || command[1] > '8' || command[3] < '1' || command[3] > '8')
	{
		cout << "Invalid Move!!source square or dest square invalid." << endl;
		return 5;
	}
	else if (this->_board[row][col]->getColor() != _turn)
	{
		cout << "Invalid Move!!source square dosent contain current player piece." << endl;
		return 2;
	}
	else if (this->_board[destRow][destCol]->getColor() == this->_board[row][col]->getColor())
	{
		cout << "Invalid move!!dest sqaure conatins current player piece." << endl;
		return 3;
	}
	else if (this->_board[row][col]->move(this->_board, row + 1, col + 1, destRow + 1, destCol + 1) == false ||
		_board[row][col]->isPieceInWay(this->_board, row, col, destRow, destCol))
	{
		cout << "Invalid move!!invalid movement of piece." << endl;
		return 6;
	}
	else if (doesMovePutKingInCheck(row, col, destRow, destCol, this->_board, command))
	{
		cout << "Invalid move!!move will cause check on yourself" << endl;
		return 4;
	}
	else
	{
		movePiece(row, col, destRow, destCol, srcSquare, dstSquare);
		if (didMoveCheckOpponent(destRow, destCol, this->_board, command))
		{
			return 1;
		}
		return 0;
	}
}

bool GameManager::doesMovePutKingInCheck(int srcRow, int srcCol, int destRow, int destCol, Piece* (&board)[8][8], string command)
{
	// Save the original state
	int kingRow = 0, kingCol = 0;
	char playerColor = board[srcRow][srcCol]->getColor();

	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if (board[row][col]->getName() == 'k' &&
				board[srcRow][srcCol]->getColor() == board[row][col]->getColor() ||
				board[row][col]->getName() == 'K' &&
				board[srcRow][srcCol]->getColor() == board[row][col]->getColor())
			{
				kingRow = row;
				kingCol = col;
				break;
			}
		}
	}
	// Backup the board state
	Piece* tempDest = board[destRow][destCol];
	Piece* tempSrc = board[srcRow][srcCol];


	// Simulate the move
	board[destRow][destCol] = board[srcRow][srcCol];
	board[srcRow][srcCol] = new Piece('#', '#', board[srcRow][srcCol]->getPosition());

	// Update king's position if the king is moved
	if (srcRow == kingRow && srcCol == kingCol) 
	{
		kingRow = destRow;
		kingCol = destCol;
	}

	// Check if the king is in check
	bool kingInCheck = false;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (board[i][j] != nullptr && board[i][j]->getColor() != '#' && board[i][j]->getColor() != playerColor)
			{
				int srcRow = i;
				int srcCol = j;

				// If opponent's piece can attack the king's position, king is in check
				if (board[i][j]->move(board, srcRow, srcCol, kingRow, kingCol) &&
					board[i][j]->isPieceInWay(board, i, j, kingRow, kingCol) == false)
				{
					kingInCheck = true;
					break;
				}
			}
		}
		if (kingInCheck) break;
	}

	// Restore the board
	board[srcRow][srcCol] = tempSrc;
	board[destRow][destCol] = tempDest;

	printf("DSD");
	return kingInCheck;
}

bool GameManager::didMoveCheckOpponent(int srcRow, int srcCol, Piece* (&board)[8][8], string command)
{
	int kingRow = 0, kingCol = 0;
	
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if (board[row][col]->getName() == 'k' &&
				board[row][col]->getColor() != board[srcRow][srcCol]->getColor() ||
				board[row][col]->getName() == 'K' &&
				board[row][col]->getColor() != board[srcRow][srcCol]->getColor())
			{
				kingRow = row;
				kingCol = col;
			}
		}
	}
	
	if(board[srcRow][srcCol]->move(board, srcRow, srcCol, kingRow, kingCol) &&
		board[srcRow][srcCol]->isPieceInWay(board, srcRow, srcCol, kingRow, kingCol) == false)
	{
		return true;
	}
	return false;
}

void GameManager::printColor()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << _board[i][j]->getColor();
			cout << ' ';
		}
		cout << "\n";
	}
}
void GameManager::movePiece(int srcRow, int srcCol, int destRow, int destCol, string srcSquare, string dstSquare)
{
	delete _board[destRow][destCol];
	if (_board[srcRow][srcCol]->getName() == 'r' || _board[srcRow][srcCol]->getName() == 'R')
	{
		_board[destRow][destCol] = new Rook(_board[srcRow][srcCol]->getName(),
			_board[srcRow][srcCol]->getColor(), dstSquare);
	}
	else if (_board[srcRow][srcCol]->getName() == 'k' || _board[srcRow][srcCol]->getName() == 'K')
	{
		_board[destRow][destCol] = new King(_board[srcRow][srcCol]->getName(),
			_board[srcRow][srcCol]->getColor(), dstSquare);
	}
	else if (_board[srcRow][srcCol]->getName() == 'p' || _board[srcRow][srcCol]->getName() == 'P')
	{
		_board[destRow][destCol] = new Pawn(_board[srcRow][srcCol]->getName(),
			_board[srcRow][srcCol]->getColor(), dstSquare);
	}
	else if (_board[srcRow][srcCol]->getName() == 'n' || _board[srcRow][srcCol]->getName() == 'N')
	{
		_board[destRow][destCol] = new Knight(_board[srcRow][srcCol]->getName(),
			_board[srcRow][srcCol]->getColor(), dstSquare);
	}
	else if (_board[srcRow][srcCol]->getName() == 'q' || _board[srcRow][srcCol]->getName() == 'Q')
	{
		_board[destRow][destCol] = new Queen(_board[srcRow][srcCol]->getName(),
			_board[srcRow][srcCol]->getColor(), dstSquare);
	}
	else if (_board[srcRow][srcCol]->getName() == 'b' || _board[srcRow][srcCol]->getName() == 'B')
	{
		_board[destRow][destCol] = new Bishop(_board[srcRow][srcCol]->getName(),
			_board[srcRow][srcCol]->getColor(), dstSquare);
	}
	delete _board[srcRow][srcCol];
	_board[srcRow][srcCol] = new Piece('#', '#', srcSquare);

	if (_turn == 'w')
	{
		_turn = 'b';
	}
	else
	{
		_turn = 'w';
	}
}

vector<vector<string>> GameManager::getPositionBoard()
{
	return positionBoard;
}