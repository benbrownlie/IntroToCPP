#include "Character.h"
#include <iostream>

Character::Character()
{
	m_health = 100;
	m_damage = 10;
	m_name;

}

Character::Character(float health, float damage)
{
	m_health = health;
	m_damage = damage;
}

Character::Character(float health, float damage, char name)
{
	m_health = health;
	m_damage = damage;
	m_name = &name;
}

void Character::attack(Character* other)
{
	other->takeDamage(getDamage());
}

void Character::createPlayer()
{
	char playerName;
	std::cout << "Please enter your name" << std::endl;
	std::cin >> playerName;
	m_name = &playerName;
	std::cout << "Welcome " << m_name;

}

float Character::takeDamage(float damageAmount)
{
	m_health -= damageAmount;
	return damageAmount;
}