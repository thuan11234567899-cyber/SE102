#pragma once

#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#define MARIO_WIDTH 14

class CBrick : public CGameObject {
public: 
	CBrick(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
};

class CMario : public CGameObject
{
protected:
	float vx;
public:
	CMario(float x, float y, float vx);
	void Update(DWORD dt);
	void Render();
};

class Yellow_Brick : public CGameObject {
	public:
		Yellow_Brick(float x, float y) : CGameObject(x, y) {};
		void Render();
		void Update(DWORD dt) {}
};

class Floor : public CGameObject {
	public:
		Floor(float x, float y,float vx =0) : CGameObject(x, y) {};
		void Render();
		void Update(DWORD dt){}
};

class Door : public CGameObject {
	public: 
		Door(float x, float y) : CGameObject(x, y) {};
		void Render();
		void Update(DWORD dt) {}
};
