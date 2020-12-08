#include <iostream>;

void guessNumber()
{
	int min = 1;
	int max = 10;
	int answer = 0;
	int userInput = 0;

	while (min <= max)
	{
		answer = (min + max) / 2;

		std::cout << "Is the number " << answer << " ";
		std::cout << " | 1. Yes | 2. No";
		std::cin >> userInput;

		std::cout << std::endl;

		if (userInput == 1)
		{
			std::cout << "Nice";
			return;
		}

		std::cout << " | 1.Higher or 2.Lower? | ";
		std::cin >> userInput;
		std::cout << std::endl;

		if (userInput == 1)
		{
			min = answer + 1;
		}

		if (userInput == 2)
		{
			max = answer - 1;
		}


	}

}

int main()
{
	

	std::cout << "Welcome to the number guessing game!";
	guessNumber();


	int num = 0;

	system("pause");
	return 0;
}