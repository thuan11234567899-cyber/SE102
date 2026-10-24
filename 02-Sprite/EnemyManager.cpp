#include "EnemyManager.h"

Enemies::Enemies() {
	
	Timespawn = 0;
}
void Enemies::Update(DWORD dt) {
	Timespawn += dt;
	if (Timespawn > 2500) {
		Timespawn = 0;
		for (int i = 0; i <3 ; i++)
		{
			

			Enemy* enemie  = new Enemy(280.0f-20.0f*i, 100.0f);
			enemies.push_back(enemie);
		}
	}
	for (auto it : enemies)
		it->Update(dt);
}

void Enemies::Render() {
	for (auto it : enemies)
		it->Render();
}