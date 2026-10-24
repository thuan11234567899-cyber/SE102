#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_TANK 50000



class Tank : public CGameObject
{
	public:
		Tank(float x, float y) : CGameObject(x, y) {}
	
	void Update(DWORD dt);
	void Render();
	void move(float dx, float dy) {
		x += dx;
		y += dy;
	}
};
