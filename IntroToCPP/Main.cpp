#include <iostream>;

void guessNumber()
{
	//Int used for the lowest number a guess can be
	int min = 1;
	//Int used for the highest number a guess can be
	int max = 10;
	//Default answer is set to 0
	int answer = 0;
	//User input by default is set to 0
	int userInput = 0;

	//While the lowest number is lower or equal to the highest number loop
	while (min <= max)
	{
		//Sets the answer to the lowest and highest number / 2 by default
		answer = (min + max) / 2;

		//Asks the user if their number is the default number
		std::cout << "Is the number " << answer << " ";
		std::cout << " | 1. Yes | 2. No";
		//Takes in user input
		std::cin >> userInput;

		std::cout << std::endl;

		//If the user answers yes
		if (userInput == 1)
		{
			std::cout << "Nice";
			return;
		}

		//If the users inputs another answer
		std::cout << " | 1.Higher or 2.Lower? | ";
		std::cin >> userInput;
		std::cout << std::endl;

		//If the answer is higher,
		if (userInput == 1)
		{
			//increments the lowest number up by 1
			min = answer + 1;
		}

		//If the answer is lower
		if (userInput == 2)
		{
			//decrements the highest number down by 1
			max = answer - 1;
		}


	}

}

int main()
{
	//At the start of the program displays welcome message and calls the guessNumber function.
	std::cout << "Welcome to the number guessing game!";
	guessNumber();


	int num = 0;

	system("pause");
	return 0;
}