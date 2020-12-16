#pragma once
class Character
{
public:
	Character();
	Character(float health, float damage);
	Character(float health, float damage, char name);

	void attack(Character* other);
	void createPlayer();
	float takeDamage(float damageAmount);
	float getDamage() { return m_damage; }
	float getHealth() { return m_health; }
	char getName() { return *m_name; }

private:
	float m_health;
	float m_damage;
	char* m_name;
};

