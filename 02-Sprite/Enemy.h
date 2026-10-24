#pragma once
#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#define ID_ANI_ENEMY 1
class Enemy : public CGameObject
{
	float vx, vy;
public:
	Enemy(float x, float y);
	void Update(DWORD dt);
	void Render();
};
