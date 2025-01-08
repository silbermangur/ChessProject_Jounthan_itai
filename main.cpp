#include <iostream>
#include "GameManager.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include <vector>



int main()
{
	string input = "";
	bool stop =true;
	GameManager g("rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1");
	

	while (stop)
	{
		cout << "Enter move: ";
		cin >> input;
		if (g.isCommandValid(input) < 2)
		{
			g.setBoard(input);
			g.printBoard();
			g.printPosition();
			g.printColor();
		}
	}
}