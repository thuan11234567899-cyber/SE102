#include "Space.h"
#include "Game.h"
#include "Debug.h"


CSpace::CSpace(float x, float y) : CGameObject(x, y)
{
	vx = 0.0f;
	vy = 0.0f;
}
void CSpace::Render()
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(ID_ANI_SPACE);	
	ani->Render(x, y);
}

void CSpace::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}