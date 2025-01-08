#include "GameManager.h"
#include <iostream>

GameManager::GameManager(string board) : positionBoard(8, vector<string>(8))
{
	boardInit(board);
	if (board[64] == '0')
	{
		_turn = 'w';
	}
	else
	{
		_turn = 'b';
	}
}

void GameManager::boardInit(std::string board)
{
	int i, j, curChar = 0;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			initPieceInBoard(board[curChar], i, j);
			curChar++;
		}
	}
}

void GameManager::initPieceInBoard(char name, int height, int width)
{
	_board[height][width] = nullptr;

	switch (name)
	{
	case '#':
		_board[height][width]->setColor(name);
		_board[height][width]->setName(name);
		break;
	case 'K':
		_board[height][width] = new King(name, 'w');
		break;
	case 'k':
		_board[height][width] = new King(name, 'b');
		break;
	case 'Q':
		_board[height][width] = new Queen(name, 'w');
		break;
	case 'q':
		_board[height][width] = new Queen(name, 'b');
		break;
	case 'R':
		_board[height][width] = new Rook(name, 'w');
		break;
	case 'r':
		_board[height][width] = new Rook(name, 'b');
		break;
	case 'N':
		_board[height][width] = new Knight(name, 'w');
		break;
	case 'n':
		_board[height][width] = new Knight(name, 'b');
		break;
	case 'B':
		_board[height][width] = new Bishop(name, 'w');
		break;
	case 'b':
		_board[height][width] = new Bishop(name, 'b');
		break;
	case 'P':
		_board[height][width] = new Pawn(name, 'w');
		break;
	case 'p':
		_board[height][width] = new Pawn(name, 'b');
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
	int destRow = '8' - command[3];  // '1' -> row 0, '2' -> row 1, etc.
	int destCol = command[2] - 'a';  // 'a' -> column 0, 'b' -> column 1, etc.
	int row = '8' - command[1];  // '1' -> row 0, '2' -> row 1, etc.
	int col = command[0] - 'a';// 'a' -> column 0, 'b' -> column 1, etc.


	if (command[0] == command[2] && command[1] == command[3])
	{
		return 7;
	}
	else if (command[0] > 'h' || command[0] < 'a' || command[2] > 'h' || command[2] < 'a'
		|| command[1] < '1' || command[1] > '8' || command[3] < '1' || command[3] > '8')
	{
		return 5;
	}
	else if (this->_board[row][col]->getColor() != this->_turn)
	{
		return 2;
	}
	else if (this->_board[destRow][destCol]->getColor() == this->_board[row][col]->getColor())
	{
		return 3;
	}
	else if (this->_board[row][col]->move(command, this->_board) == false || 
		_board[row][col]->isPieceInWay(command, this->_board, row, col, destRow, destCol) == false)
	{
		return 6;
	}
	else if (_board[row][col]->isCheck(this->_board, destRow, destCol))
	{
		return 8;
	}
	return 0;
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
bool GameManager::setBoard(string command)
{
	int row, col, h;
	string start = command.substr(0, 2);
	string end = command.substr(2, 2);

	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
		{
			if (_board[row][col]->getPosition() == start)
			{
				if (_board[row][col]->move(command, this->_board))
				{
					movePiece(end, row, col);
					if (this->turnCounter == 0)
					{
						this->turn = 'w';
						this->turnCounter++;
					}
					else
					{
						this->turn = 'b';
						this->turnCounter--;
					}
					return true;
				}
				else
				{
					return false;
				}
				break;
			}
		}
		
		if (col < 8 && _board[row][col]->getPosition() == start)
		{
			break;
		}
		
	}
	return false;
}

void GameManager::movePiece(string dest, int row, int col)
{
	int sourceRow = row, sourceCol = col, destRow, destCol;
	bool stop = false;
	
	for (destRow = 0; destRow < 8; destRow++)
	{
		for (destCol = 0; destCol < 8; destCol++)
		{
			if (_board[destRow][destCol]->getPosition() == dest)
			{
				delete _board[destRow][destCol];
				_board[destRow][destCol] = new Rook(_board[row][col]->getName(), _board[row][col]->getColor(), dest);
				delete _board[row][col];
				_board[row][col] = new Piece();
				_board[row][col]->setColor(' ');
				_board[row][col]->setName('#');
				_board[row][col]->setPosition(this->positionBoard[row][col]);
				break;
			}

		}

		if (stop)
		{
			break;
		}
	}
}

vector<vector<string>> GameManager::getPositionBoard()
{
	return positionBoard;
}


