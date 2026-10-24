#include "Bullet.h"

Bullet::Bullet(float x, float y) : CGameObject(x, y)
{
    vx = 0.5f;
}
void Bullet::Update(DWORD dt)
{
    x += vx * dt;
}

void Bullet::Render()
{
    LPANIMATION ani = CAnimations::GetInstance()->Get(ID_ANI_Bullet);
    ani->Render(x, y);
}