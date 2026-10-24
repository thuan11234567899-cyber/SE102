#include "Enemy.h"

Enemy::Enemy(float x, float y) : CGameObject(x, y)
{
    vx = 0.05f;
}
void Enemy::Update(DWORD dt)
{
    x -= vx * dt;
    while (x == 100.0f)
    {

    }
}

void Enemy::Render()
{
    LPANIMATION ani = CAnimations::GetInstance()->Get(ID_ANI_ENEMY);
    ani->Render(x, y);
}