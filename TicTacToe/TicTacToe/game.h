#include<iostream>
#include<time.h>
#include<ctime>


using namespace std;

class board 
{
private:

	int line, column;

	int v1;

public:
	
	int checkWhoStarts()
	{
		srand(time(NULL));

		 v1 = rand() % 2;

		if (v1 == 1)
			return 1;
		else if (v1 == 0)
		{
			return 0;
		}
	}


	
	void playGame(int n,int matrix[100][100],int currentPlayer, int playerChoice)
	{
		    srand(time(NULL));
		
			line = rand() % n;
	
			column = rand() % n;

			while (matrix[line][column] != 0 || line >= n || column >= n || line >= n && column >= n)
			{

				if (line >= n || column >= n || line >= n && column >= n)
				{
					
					line = rand() % n;
					
					column = rand() % n;
				
				}

				else if (matrix[line][column] != 0)
				{
				
					line = rand() % n;
				
					column = rand() % n;
			
				}
		
			}

			
			if (currentPlayer == 1 && playerChoice == 1)
			{
				matrix[line][column] = playerChoice;

				updateMatrix(n, matrix, playerChoice);

			}

			

			if (currentPlayer == 2 && playerChoice == 2)
			{
				matrix[line][column] = playerChoice;

				updateMatrix(n, matrix, playerChoice);

			}
		
	}

	void updateMatrix(int n,int matrix[100][100],int playerChoice)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(matrix[i][j] != 1 && matrix[i][j] != 2)

				matrix[i][j] = 0;

				else
				
				matrix[line][column] = playerChoice;
			}
		}
	}

	void showMatrix(int n,int matrix[100][100])
	{

		cout << endl;
		

		cout << "[[";

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << matrix[i][j] << " ";
			}
			if (i != n - 1)
				cout << "]\n [";
			else
				cout << "]]" << endl;
		}
	}

};

class checkRules
{
private:

	int save;

public:

	int checkIfBoardFull(int n, int matrix[100][100])
	{
		int k=0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == 0)
					k++;
			}
		}
		if (k == 0)
		{
			cout << "The board is full,there are no posible moves !" << k << endl;
		
			return 0;
		}
		else
			return 1;
	}

	int checkTheLines(int n, int matrix[100][100], int playerChoice)
	{
		if (playerChoice == 1) //pentru verificarea pe linie : player 1
		{
			int k = 0;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{

				
					if (matrix[i][j] != playerChoice && k < n && j == n - 1)
					{
						k = 0;
					}
					if (matrix[i][j] == playerChoice && k < n)
					{

						k++;
				
						if (k == n)
							save = i;
						if (j == n - 1 && k < n)
						{

							k = 0;
					
						}

					}

					else if (k == n)
					{

						break;
					}

				}
			}
			if (k == n)
			{
				cout << "k=" << k << " pe linia " << save << "si player 1 castiga" << endl;
			
				return 1;
				
			}
			else
			return 0;
			
		}

		if (playerChoice == 2) // pentru verificarea pe linie : player2
		{

			int k = 0;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{

		
					if (matrix[i][j] != playerChoice && k < n && j == n - 1)
					{
						k = 0;
					}
					if (matrix[i][j] == playerChoice && k < n)
					{

						k++;
		
						if (k == n)
							save = i;
						if (j == n - 1 && k < n)
						{
				
							k = 0;
		
						}

					}

					else if (k == n)
					{

						break;
					}

				}
			}
			if (k == n)
			{
				cout << "k=" << k << " pe linia " << save << " si player 2 castiga" << endl;
			
				return 1;

			}
			else
			return 0;
		}
	}

	int checkTheColumns(int n, int matrix[100][100], int playerChoice)
	{
		if (playerChoice == 1) //pentru verificarea pe coloana player1
		{
			int k = 0;

			for (int j = 0; j < n; j++)
			{
				for (int i = 0; i < n; i++)
				{

					if ((matrix[i][j] == playerChoice && k < n && i == 0)|| (matrix[i][j] != playerChoice && k < n && i == 0))
					{
						k = 0;

					}

					if (matrix[i][j] == playerChoice && k < n)
					{
						k++;
						if (k == n)
							save = j;
					}

				}
			}
			if (k == n)
			{
				cout << "K = " << k << " pe coloana " << save << "si player 1 castiga !" << endl;


				return 1;
			}
			else
				return 0;
		}

		if (playerChoice == 2) //pentru verificarea pe coloana player2
		{
			int k = 0;

			for (int j = 0; j < n; j++)
			{
				for (int i = 0; i < n; i++)
				{

					if ((matrix[i][j] == playerChoice && k < n && i == 0)|| (matrix[i][j] != playerChoice && k < n && i == 0))
					{
						k = 0;

					}

					if (matrix[i][j] == playerChoice && k < n)
					{
						k++;

						if (k == n)
							save = j;
					}

				}
			}
			if (k == n)
			{
				cout << "K = " << k << " pe coloana " << save << " si player 2 castiga !" << endl;

				return 1;
			}
			else

				return 0;
		}
	}

	int checkTheDiagonalOne(int n, int matrix[100][100], int playerChoice)
	{
		if (playerChoice == 1) //verificare pe diagonala1 pentru player1
		{
			int k = 0;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i == j && matrix[i][j] == playerChoice)
					{
						k++;
					}
				}
			}

			if (k == n)
			{
				cout << "k pe diagonala e :" << k << " pe diagonala1 si player1 castiga !" << endl;

				return 1;
			}
			else
				return 0;

		}

		if (playerChoice == 2) //verificare pe diagonala1 pentru player2
		{
			int k = 0;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i == j && matrix[i][j] == playerChoice)
					{
						k++;
					}
				}
			}

			if (k == n)
			{

				cout << "k pe diagonala e :" << k << " pe diagonala1 si player2 castiga !" << endl;


				return 1;
			}

			else

				return 0;

		}
	}

	int checkTheDiagonalTwo(int n, int matrix[100][100], int playerChoice)
	{
		if (playerChoice == 1) //pentru verificarea pe diagoanala2 pentru player1
		{
			int k = 0;

			int i = 0;
			int j = n - 1;

			while (i < n && j >= 0)
			{

				if (matrix[i][j] == playerChoice)
				{
					k++;
				}

				i++;
				j--;
			}
			

			if (k == n)
			{
				cout << "k = " << k << " pe diagonala2 si player1 castiga !" << endl;

				return 1;
			}
			else
				return 0;

		}

		if (playerChoice == 2) // pentru verificarea pe diagoanal2 pentru player2
		{
			int k = 0;

			int i = 0;
			int j = n - 1;

			while (i < n && j >= 0)
			{
				

				if (matrix[i][j] == playerChoice)
				{
					k++;
				
				}

				i++;
				j--;
			}

			if (k == n)
			{
				cout << "k = " << k << " pe diagonala2 si player2 castiga !" << endl;

				return 1;
			}
			else
				return 0;

		}
	}

};


class gameRules  : public checkRules,public board
{


public:
	

	int checkTheGame(int n, int matrix[100][100], int playerChoice,int currentPlayer)
	{
		
			if (checkTheLines(n, matrix, playerChoice) == 1)
			{

				showMatrix(n, matrix);

				return 0;
			}
			else  if (checkTheColumns(n, matrix, playerChoice) == 1)
			{

				
				showMatrix(n, matrix);

				return 0;
			}
			else if (checkTheDiagonalOne(n, matrix, playerChoice) == 1)
			{

				showMatrix(n, matrix);

				return 0;
			}
			else if (checkTheDiagonalTwo(n, matrix, playerChoice) == 1)
			{

				showMatrix(n, matrix);

				return 0;
			}
			else if (checkIfBoardFull(n, matrix) == 0)
			{
				showMatrix(n, matrix);

				cout << "It`s a tie !" << endl;
				return 0;
			}

			return 1;
	}

	
};
