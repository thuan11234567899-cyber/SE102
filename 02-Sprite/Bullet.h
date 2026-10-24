#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#define ID_ANI_Bullet 1000
class Bullet : public CGameObject
{
	float vx;
public:
	Bullet(float x, float y);
	void Update(DWORD dt);
	void Render();
};
