#include <iostream>;

int main()
{
	int num = 0;
	std::cout << num << std::endl;

	std::cin >> num;

	if (num == 3 || num%3 == 0)
	{
		std::cout << "Fizz: " << num << std::endl;
	}
	else if (num == 5 || num % 5 == 0)
	{
		std::cout << "Buzz: " << num << std::endl;
	}
	else if (num % 5 == 0 && num % 3 == 0)
	{
		std::cout << "FizzBuzz: " << num << std::endl;
	}

	system("pause");
	return 0;
}