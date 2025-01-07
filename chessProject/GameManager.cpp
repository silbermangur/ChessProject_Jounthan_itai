#include "GameManager.h"

GameManger::GameManger(string gameBoard) : positionBoard(8, vector<string>(8))
{
	int n = 0;
	int positionNum = 8;
	char positionChar = 'a';
	
	board[0][0] = new Rock('r', 'b', "a8");
	board[0][7] = new Rock('r', 'b', "h8");
	board[7][0] = new Rock('r', 'w', "a1");
	board[7][7] = new Rock('r', 'w', "h1");
	

	//initlize board to starting postion
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j ++ )
		{
			if (board[i][j] == nullptr) 
			{
				board[i][j] = new Piece(); 
			}
			//initilizing color for black
			if (i < 1)
			{
				board[i][j]->setColor('b');
			}
			//initilizing color for white
			else if (i > 6)
			{
				board[i][j]->setColor('w');
			}
			//initilizng names for pieces
			board[i][j]->setName(gameBoard[n]);
			//initilizng position for pieces
			this->positionBoard[i][j] = (positionChar + to_string(positionNum));
			board[i][j]->setPosition(positionChar+to_string(positionNum));
			positionChar++;
			n++;
		}
		positionNum--;
		positionChar -= 8;
	}
}

GameManger::~GameManger()
{
	for (int i = 0; i < 8; ++i) 
	{
		for (int j = 0; j < 8; ++j) 
		{
			delete board[i][j];  // Delete the Piece (or derived object) pointed to by board[i][j]
		}
	}
}

void GameManger::printBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << board[i][j]->getName();
			cout << ' ';
		}
		cout << "\n";
	}
}

void GameManger::printPosition()
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

int GameManger::isCommandValid(string command)
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
	else if (this->board[row][col]->getColor() != this->turn)
	{
		return 2;
	}
	else if (this->board[destRow][destCol]->getColor() == this->board[row][col]->getColor())
	{
		return 3;
	}
	else if (this->board[row][col]->mov(command, this->board) == false || 
		board[row][col]->isPieceInWay(command, this->board, row, col, destRow, destCol) == false)
	{
		return 6;
	}
	else if (board[row][col]->isCheck(this->board, destRow, destCol))
	{
		return 8;
	}
	return 0;
}

void GameManger::printColor()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << board[i][j]->getColor();
			cout << ' ';
		}
		cout << "\n";
	}
}
bool GameManger::setBoard(string command)
{
	int row, col, h;
	string start = command.substr(0, 2);
	string end = command.substr(2, 2);

	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
		{
			if (board[row][col]->getPosition() == start)
			{
				if (board[row][col]->mov(command, this->board))
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
		
		if (col < 8 && board[row][col]->getPosition() == start)
		{
			break;
		}
		
	}
	return false;
}

void GameManger::movePiece(string dest, int row, int col)
{
	int sourceRow = row, sourceCol = col, destRow, destCol;
	bool stop = false;
	
	for (destRow = 0; destRow < 8; destRow++)
	{
		for (destCol = 0; destCol < 8; destCol++)
		{
			if (board[destRow][destCol]->getPosition() == dest)
			{
				delete board[destRow][destCol];
				board[destRow][destCol] = new Rock(board[row][col]->getName(), board[row][col]->getColor(), dest);
				delete board[row][col];
				board[row][col] = new Piece();
				board[row][col]->setColor(' ');
				board[row][col]->setName('#');
				board[row][col]->setPosition(this->positionBoard[row][col]);
				break;
			}

		}

		if (stop)
		{
			break;
		}
	}
}

vector<vector<string>> GameManger::getPositionBoard()
{
	return positionBoard;
}


