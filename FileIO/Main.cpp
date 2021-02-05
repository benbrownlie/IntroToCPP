#include <iostream>
#include <fstream>
#include "Character.h"

int numbers = 0;
std::fstream file;

bool saveTest(int number)
{
	std::cout << "Enter a number" << std::endl;
	std::cin >> number;

	file.open("savefile.txt", std::ios::app | std::ios::binary);

	if (!file.is_open())
	{
		return false;
	}

	file.write((char*)&number, sizeof(int));

	file.close();
	std::cout << "Number saved" << std::endl;
	return true;
}

bool loadTest(int number)
{
	std::cout << "Number loaded" << std::endl;
	file.open("savefile.txt", std::ios::in | std::ios::binary);

	if (!file.is_open())
		return false;

	file.seekg(sizeof(int), std::ios::beg);
	file.read((char*)&number, sizeof(int));

	file.close();

	std::cout << number << std::endl;
	return true;
}

bool binaryFileExample()
{
	//Initialize characters
	Character sbeve = Character();
	sbeve.health = 100;
	sbeve.damage = 12;
	Character sbeve2 = Character();
	sbeve2.health = 110;
	sbeve2.damage = 13;
	Character sbeve3 = Character();
	sbeve3.health = 111;
	sbeve3.damage = 14;

	//Create an instance of file stream.
	std::fstream file;

	//Open the file we want to save to. The first argument is the file path.
	//The second is what we will be doing with the file(reading or writing).
	//Followed by any extra parameters. In this case, std::ios::binary
	//To make the file create a binary file.
	file.open("savefile.txt", std::ios::app | std::ios::binary);

	//Check to see if the file is open before using it.
	if (!file.is_open())
		return false;

	//Write all the characters to file.
	file.write((char*)&sbeve, sizeof(Character));
	file.write((char*)&sbeve2, sizeof(Character));
	file.write((char*)&sbeve3, sizeof(Character));

	//Close the file once writing is complete.
	file.close();

	//Create a character to store loaded data.
	Character sbeve4 = Character();

	//Open the file to load from.
	file.open("savefile.txt", std::ios::in | std::ios::binary);

	//Check to see if the file is open.
	if (!file.is_open())
		return false;

	//Position the marker to two characters away from the beginning.
	file.seekg(sizeof(Character) * 2, std::ios::beg);

	//Set the character to be the value read from the file.
	file.read((char*)&sbeve4, sizeof(Character));

	//Print the results.
	std::cout << sbeve4.health << std::endl;
	std::cout << sbeve4.damage << std::endl;

	//Close the file.
	file.close();
	return true;
}

bool textFileExample()
{
	///Test Files
	Character player = Character();
	player.health = 100;
	player.damage = 5;

	//Example of saving to a text file
	std::fstream file;
	file.open("save.txt", std::ios::out | std::ios::_Nocreate);

	//Checks if the file isnt opened. If so return from main
	if (!file.is_open())
	{
		return 1;
	}

	//Writes to the text file
	file << player.health << std::endl;
	file << player.damage;

	//Be sure to close file when done
	file.close();

	//Example of loading from a text file
	Character player2 = Character();

	file.open("save.txt", std::ios::in);
	file >> player2.health;
	file >> player2.damage;

	//BE SURE to close file when done
	file.close();

	std::cout << player2.health << std::endl;
	std::cout << player2.damage << std::endl;
	return 0;
}


int main()
{
	saveTest(numbers);
	loadTest(numbers);
	system("pause");

	return 0;
}