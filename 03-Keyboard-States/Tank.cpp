#include "Tank.h"

void Tank::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_TANK)->Render(x, y);
}
void Tank::Update(DWORD dt) {
	// Tank does not move, so no update logic is needed
	x += vx * dt;
	y += vy * dt;
}