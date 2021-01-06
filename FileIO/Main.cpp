#include <iostream>
#include <fstream>
#include "Character.h"

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

bool binarySave(Character custom)
{
	std::fstream file;

	file.open("savefile.txt", std::ios::app | std::ios::binary);

	if (!file.is_open())
	{
		return false;
	}

	file.write((char*)&custom, sizeof(Character));
	file.close();

	return true;
}

bool binaryLoad(Character custom)
{
	std::fstream file;

	file.open("savefile.txt", std::ios::app | std::ios::binary);

	if (!file.is_open())
		return false;

	file.seekg(sizeof(Character), std::ios::beg);

	file.read((char*)&custom, sizeof(Character));

	std::cout << custom.health << std::endl;
	std::cout << custom.damage << std::endl;

	file.close();
	return true;
}

void saveLoadTest()
{
	//Creates variable for the players choice
	int choice;
	//Displays welcome message and askes wether the player would like to create a character
	//or load from a previously saved character
	std::cout << "\nWelcome! Please create or load a character." << std::endl;
	std::cout << "\n|1|Create |2|Load" << std::endl;
	//Takes in the player's choice
	std::cin >> choice;

	if (choice == 1)
	{
		int choice;
		std::cout << "\nYou created a new character!";
		Character player = Character();
		player.health = 100;
		player.damage = 10;
		std::cout << "\nHealth: " << player.health;
		std::cout << "\nDamage: " << player.damage << std::endl;
		std::cout << "\nWould you like to save?";
		std::cout << "\n|1|Yes |2|No" << std::endl;
		std::cin >> choice;

		if (choice == 1)
		{
			binarySave(player);
		}

		else
		{
			std::cout << "Wrong Answer";
		}
	}

	else
	{
		binaryLoad();
	}


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

int main()
{
	saveLoadTest();
	system("pause");

	return 0;
}