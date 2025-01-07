
#include "GameManager.h"
#include "Rock.h"


int main()
{
	string input = "";
	bool stop =true;
	GameManger g("rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1");
	

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