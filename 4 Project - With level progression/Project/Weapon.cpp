#include <iostream>
#include <windows.h>

#include "Weapon.h"

void Weapon::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)m_color);

	std::cout << "1";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}
