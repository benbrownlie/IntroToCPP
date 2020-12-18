#include "Game.H"
#include <iostream>
#include <fstream>

void Game::run()
{
	start();

	while (!getGameOver())
	{
		update();
		draw();

		system("pause");
	}

	end();
}

void Game::start()
{
	m_player1 = new Character(10, 10);
	m_player1->createPlayer();
	m_player2 = new Character(10, 10);
}

int Game::saveGame()
{
	std::fstream file;
	file.open("save.txt", std::ios::out | std::ios::_Nocreate);

	//Checks if the file isnt opened. If so return from main
	if (!file.is_open())
	{
		return 1;
	}

	file << m_player1->getHealth() << std::endl;
	file << m_player1->getDamage() << std::endl;
	file.close();

	return 0;
}

void Game::combatLoop()
{
	while (m_player1->getIsAlive() && m_player2->getIsAlive())
	{
		char input = 0;
		std::cout << "\nWhat will you do?";
		std::cout << "\n\|1|Attack |2|Block |3|Save" << std::endl;
		std::cin >> input;

		if (input == 1)
		{
			std::cout << "\nYou attack player2 for " << m_player1->getDamage();
			m_player1->attack(m_player2);
		}

		else if (input == 2)
		{
			std::cout << "\nYou blocked the hit";
		}

		else if (input == 3)
		{
			std::cout << "\nYou saved the game";
			saveGame();
		}

	}
}

void Game::update()
{
	combatLoop();
}

void Game::draw()
{
	std::cout << "\nPlayer1 health is: " << m_player1->getHealth();
	std::cout << "\nPlayer2 health is: " << m_player2->getHealth();
	std::cout << std::endl;
}

void Game::end()
{
	delete m_player1;
	delete m_player1;
}