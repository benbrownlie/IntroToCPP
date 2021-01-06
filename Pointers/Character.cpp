#include "Character.h"
#include <iostream>

Character::Character()
{
	m_health = 100;
	m_damage = 10;
}

Character::Character(float health, float damage)
{
	m_health = health;
	m_damage = damage;
}

void Character::attack(Character* other)
{
	other->takeDamage(getDamage());
}

void Character::createPlayer()
{
	//Temporarily commented out player name creation

	//char playerName;
	std::cout << "Please enter your name" << std::endl;
	//std::cin >> playerName;
	//m_name = &playerName;
	std::cout << "Welcome default!";

}

float Character::takeDamage(float damageAmount)
{
	m_health -= damageAmount;
	return damageAmount;
}