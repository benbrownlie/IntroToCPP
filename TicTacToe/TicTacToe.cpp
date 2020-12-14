#include <iostream>

char board[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
char decision = ' ';
bool gameOver = false;

void gameBoard()
{
    //Draws out the tic tac toe board
    for (int i = 0; i < 3; i++)
    {
        for (int n = 0; n < 3; n++)
        {
            board[i][n] = '*';
            std::cout << board[i][n];
        }
    }
}

void TicTacToe()
{

    while (!gameOver)
    {
        std::cout << "Where would you like to place your token?\n";
        std::cout << "1. Top Left, 2. Top Middle, 3. Top Right,\n 4. Mid Left, 5. Mid Middle, 6. Mid Right,\n 7. Bot Left, 8. Bot Middle, 9. Bot Right\n";
        std::cout << board << std::endl;
        std::cin >> decision;
        system("cls");
    }


}

int main()
{
    //std::cout << "Welcome to Tic Tac Toe!" << "Player1 please enter a name!";
    //std::cout << std::endl;
    gameBoard();

    system("pause");
}
