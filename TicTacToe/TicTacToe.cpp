#include <iostream>

char board[3][3] = { { 0,0,0 }, {0,0,0}, {0,0,0} } ;
bool gameOver = false;
char player1[24];
bool player1Turn = true;
char player2[24];
int choice;

void getName()
{
	//Asks for player names and sets player1/player2 char array to entered name
	std::cout << "Hello player! Please enter a name" << std::endl;
	std::cin >> player1;
	std::cout << "Welcome " << player1 << std::endl;

	std::cout << "Hello player2! Please enter a name" << std::endl;
	std::cin >> player2;
	std::cout << "Welcome " << player2 << std::endl;
}

void drawBoard()
{
	//Draws out the tic tac toe board
	for (int i = 0; i < 3; i++)
	{
		for (int n = 0; n < 3; n++)
		{
			board[i][n] = '0';
			std::cout << " " << board[i][n];
		}
		std::cout << std::endl;
	}
}

void ticTacToe()
{
	if (player1Turn)
	{
		std::cout << "It's your turn " << player1 << " make your move" << std::endl;
	}

	else
	{
		std::cout << "It's your turn " << player2 << " make your move" << std::endl;
	}

	if (player1Turn)
	{
		std::cin >> choice;
		switch(choice)
		{
		case 1:
			if (choice == 1 && board[0][0] == '0')
			{
				board[0][0] = 'X';
				player1Turn = !player1Turn;
			}
			break;

		case 2:
			if (choice == 2 && board[0][1] == '0')
			{
				board[0][1] = 'X';
				player1Turn = !player1Turn;
			}

		}
	}
}

int main()
{
	getName();

	while (!gameOver)
	{
		drawBoard();
		ticTacToe();
		system("pause");
	}
}
