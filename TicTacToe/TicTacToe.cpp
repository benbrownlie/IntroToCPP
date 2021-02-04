#include <iostream>

char board[3][3] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
bool gameOver = false;
int choice;
char token1;
char token2;
char player1[20];
char player2[20];

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

void TicTacToe()
{

    while (!gameOver)
    {
        system("cls");
    }


}

void makeChoice()
{
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        break;
    }
}

void checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == 1 &&
            board[1][i] == 1 &&
            board[2][i] == 1)
        {
            gameOver == true;
        }

        else if (board[i][0] == 1 &&
            board[i][1] == 1 &&
            board[i][2] == 1)
        {
            gameOver == true;
        }
    }

    if (board[0][0] == 1
        && board[1][1] == 1
        && board[2][2] == 1)
    {
        gameOver == true;
    }

    else if (board[0][2] == 1
        && board[1][1] == 1
        && board[2][0] == 1)
    {
        gameOver == true;
    }
}

int main()
{
    //std::cout << "Welcome to Tic Tac Toe!" << "Player1 please enter a name!";
    //std::cout << std::endl;
    drawBoard();

    system("pause");
}
