#pragma once
#include "PlacableActor.h"

class Key;
class Weapon;

class Player : public PlacableActor
{
public:
	Player();

	bool HasKey();
	bool HasKey(ActorColor color);
	void PickupKey(Key* key);
	void UseKey();
	void DropKey();
	Key* GetKey() { return m_pCurrentKey; }

	bool HasWeapon();
	void PickupWeapon(Weapon* weapon);
	void UseWeapon();
	void DropWeapon();
	Weapon* GetWEapon() { return pCurrentWeapon; }

	void AddMoney(int money) { m_money += money; }
	int GetMoney() { return m_money; }

	int GetLives() { return m_lives; }
	void DecrementLives() { m_lives--; }

	virtual ActorType GetType() override { return ActorType::Player; }
	virtual void Draw() override;
private:
	Key* m_pCurrentKey;
	Weapon* pCurrentWeapon;
	int m_money;
	int m_lives;
};
