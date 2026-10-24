#pragma once
#include "Enemy.h"
#include <vector>

class Enemies {
	vector<Enemy*> enemies;
	DWORD Timespawn;
public:
	Enemies();
	void Update(DWORD dt);
	void Render();
};