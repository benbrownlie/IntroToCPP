#pragma once
class Character
{
public:
	Character();
	Character(float health, float damage);

	void attack(Character* other);
	void createPlayer();
	float takeDamage(float damageAmount);
	float getDamage() { return m_damage; }
	float getHealth() { return m_health; }
	float getIsAlive() { return m_health > 0; }

private:
	float m_health;
	float m_damage;
};

