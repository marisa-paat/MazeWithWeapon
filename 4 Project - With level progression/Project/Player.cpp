#include <iostream>

#include "Player.h"
#include "Key.h"
#include "Weapon.h"
#include "AudioManager.h"

using namespace std;

constexpr int kStartingNumberOfLives = 3;

Player::Player()
	: PlacableActor(0, 0)
	, pCurrentWeapon (nullptr)
	, m_pCurrentKey(nullptr)
	, m_money(0)
	, m_lives(kStartingNumberOfLives)
{

}
bool Player::HasWeapon()
{
	return pCurrentWeapon != nullptr;
}

bool Player::HasKey()
{
	return m_pCurrentKey != nullptr;
}

bool Player::HasKey(ActorColor color)
{
	return true;// HasKey() && m_pCurrentKey->GetColor() == color;
}

void Player::PickupWeapon(Weapon* weapon)
{
	pCurrentWeapon = weapon;
}

void Player::PickupKey(Key* key)
{
	m_pCurrentKey = key;
}

void Player::UseWeapon()
{
	if (pCurrentWeapon)
	{
		pCurrentWeapon->Remove();
		pCurrentWeapon = nullptr;
	}
}

void Player::UseKey()
{
	if (m_pCurrentKey)
	{
		m_pCurrentKey->Remove();
		m_pCurrentKey = nullptr;
	}
}

void Player::DropWeapon()
{
	if (pCurrentWeapon)
	{
		AudioManager::GetInstance()->PlayWeaponDropSound();
		pCurrentWeapon->Place(m_pPosition->x, m_pPosition->y);
		pCurrentWeapon = nullptr;
	}
}

void Player::DropKey()
{
	if (m_pCurrentKey)
	{
		AudioManager::GetInstance()->PlayKeyDropSound();
		m_pCurrentKey->Place(m_pPosition->x, m_pPosition->y);
		m_pCurrentKey = nullptr;
	}
}

void Player::Draw()
{
	cout << "@";
}
