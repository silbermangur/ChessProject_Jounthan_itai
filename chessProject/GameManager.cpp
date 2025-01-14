#include "GameManager.h"

GameManger::GameManger(string gameBoard) : positionBoard(8, vector<string>(8))
{
	int n = 0;
	int positionNum = 8;
	char positionChar = 'a';
	board[0][3] = new King('k', 'b', "d8");
	board[7][3] = new King('K', 'w', "d1");
	board[0][0] = new Rock('r', 'b', "a8");
	board[0][7] = new Rock('r', 'b', "h8");
	board[7][0] = new Rock('R', 'w', "a1");
	board[7][7] = new Rock('R', 'w', "h1");
	board[0][1] = new Knight('n', 'b', "b8");
	board[0][6] = new Knight('n', 'b', "g8");
	board[7][1] = new Knight('N', 'w', "b1");
	board[7][6] = new Knight('N', 'w', "g1");
	board[0][2] = new Bishop('b', 'b', "c8");
	board[0][5] = new Bishop('b', 'b', "f8");
	board[7][2] = new Bishop('B', 'w', "c1");
	board[7][5] = new Bishop('B', 'w', "f1");
	board[0][4] = new Queen('q', 'b', "e8");
	board[7][4] = new Queen('Q', 'w', "e1");

	//initlize board to starting postion
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j ++ )
		{
			if (board[i][j] == nullptr) 
			{
				board[i][j] = new Piece(); 
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
			}
			
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
	else if (this->board[row][col]->getColor() != this->turn)
	{
		cout << "Invalid Move!!source square dosent contain current player piece." << endl;
		return 2;
	}
	else if (this->board[destRow][destCol]->getColor() == this->board[row][col]->getColor())
	{
		cout << "Invalid move!!dest sqaure conatins current player piece." << endl;
		return 3;
	}
	else if (this->board[row][col]->mov(row, col, destRow, destCol , this->board) == false || 
		board[row][col]->isPieceInWay(this->board, row, col, destRow, destCol))
	{
		cout << "Invalid move!!invalid movement of piece." << endl;
		return 6;
	}
	else if (doesMovePutKingInCheck(row, col, 
		destRow, destCol, this->board, command))
	{
		cout << "Invalid move!!move will cause check on yourself" << endl;
		return 4;
	}
	else
	{
		movePiece(row, col, destRow, destCol, srcSquare, dstSquare);
		if (didMoveCheckOpponent(destRow, destCol, this->board, command))
		{
			return 1;
		}
		return 0;
	}
}

bool GameManger::doesMovePutKingInCheck(int srcRow, int srcCol, int destRow, int destCol, Piece* (&board)[8][8], string command)
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
	board[srcRow][srcCol] = new Piece('#', ' ', board[srcRow][srcCol]->getPosition());

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
			if (board[i][j] != nullptr && board[i][j]->getColor() != ' ' && board[i][j]->getColor() != playerColor)
			{
				int srcRow = i;
				int srcCol = j;

				// If opponent's piece can attack the king's position, king is in check
				if (board[i][j]->mov(srcRow, srcCol, kingRow, kingCol, board) &&
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

	return kingInCheck;
}

bool GameManger::didMoveCheckOpponent(int srcRow, int srcCol, Piece* (&board)[8][8], string command)
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
	
	if(board[srcRow][srcCol]->mov(srcRow, srcCol, kingRow, kingCol, board) &&
		board[srcRow][srcCol]->isPieceInWay(board, srcRow, srcCol, kingRow, kingCol) == false)
	{
		return true;
	}
	return false;
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
void GameManger::movePiece(int srcRow, int srcCol, int destRow, int destCol, string srcSquare, string dstSquare)
{
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
	delete board[destRow][destCol];
	if (board[srcRow][srcCol]->getName() == 'r' || board[srcRow][srcCol]->getName() == 'R')
	{
		board[destRow][destCol] = new Rock(board[srcRow][srcCol]->getName(),
			board[srcRow][srcCol]->getColor(), dstSquare);
	}
	else if (board[srcRow][srcCol]->getName() == 'k' || board[srcRow][srcCol]->getName() == 'K')
	{
		board[destRow][destCol] = new King(board[srcRow][srcCol]->getName(),
			board[srcRow][srcCol]->getColor(), dstSquare);
	}
	else if (board[srcRow][srcCol]->getName() == 'n' || board[srcRow][srcCol]->getName() == 'N')
	{
		board[destRow][destCol] = new Knight(board[srcRow][srcCol]->getName(),
			board[srcRow][srcCol]->getColor(), dstSquare);
	}
	else if (board[srcRow][srcCol]->getName() == 'b' || board[srcRow][srcCol]->getName() == 'B')
	{
		board[destRow][destCol] = new Bishop(board[srcRow][srcCol]->getName(),
			board[srcRow][srcCol]->getColor(), dstSquare);
	}
	else if (board[srcRow][srcCol]->getName() == 'q' || board[srcRow][srcCol]->getName() == 'Q')
	{
		board[destRow][destCol] = new Queen(board[srcRow][srcCol]->getName(),
			board[srcRow][srcCol]->getColor(), dstSquare);
	}
	delete board[srcRow][srcCol];
	board[srcRow][srcCol] = new Piece('#', ' ', srcSquare);
}

vector<vector<string>> GameManger::getPositionBoard()
{
	return positionBoard;
}
