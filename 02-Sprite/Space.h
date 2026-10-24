#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#define ID_ANI_SPACE 500
class CSpace : public CGameObject
{
	float vx, vy;
public:
	CSpace(float x, float y);
	void Update(DWORD dt);
	void Render();
	void Move(float dx, float dy) {
		x += dx;
		y += dy;
	}
	void Setstate(float vx, float vy) {
		this->vx = vx;
		this->vy = vy;
	}
	float getX() { return x; }
	float getY() { return y; }
};
