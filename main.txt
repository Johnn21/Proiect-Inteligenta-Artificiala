#include <iostream>
#include<string>
#include<time.h>
#include"game.h"


using namespace std;

int main()
{
	int matrix[100][100];

	const int n = 3; //de aici se seteaza numarul de casute din joc (n*n)

	srand(time(NULL));

	cout << "TIC TAC TOE !!!" << endl;

	cout << n << " * " << n << " matrix" << endl;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}
	
	board b;

	int player1 = 1; //player 1 va juca cu cifra '1'
	int player2 = 2; // player 2 va juca cu cifra '2'
	int currentPlayer;
	int playerChoice = 0;

	if (b.checkWhoStarts() == 0)
	{
		currentPlayer = player1;
	}
	else
	{
		currentPlayer = player2;
	}

		gameRules g;
		

		while (g.checkTheGame(n, matrix, playerChoice,  currentPlayer))
		{

			while (playerChoice != currentPlayer)
			{
				if (playerChoice != currentPlayer)
				{

					playerChoice = rand() % 3;

				}
			}
			b.playGame(n, matrix, currentPlayer, playerChoice);

			if (currentPlayer == player1)
				currentPlayer = player2;
			else if (currentPlayer == player2)
				currentPlayer = player1;


		}

	system("PAUSE");

}

	

