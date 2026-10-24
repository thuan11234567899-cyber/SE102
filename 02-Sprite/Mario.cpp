#include "Game.h"
#include "Mario.h"
#include <string>
CMario::CMario(float x, float y, float vx):CGameObject(x, y)
{
	this->vx = vx;
};

void CMario::Update(DWORD dt)
{
	x += vx*dt;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= 0 || x >= BackBufferWidth - MARIO_WIDTH) {

		vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - MARIO_WIDTH)
		{
			x = (float)(BackBufferWidth - MARIO_WIDTH);
		}
	}
}

void CMario::Render()
{
	LPANIMATION ani;

	//[RED FLAG][TODO]: Student needs to think about how to associate this animation/asset to Mario!!
	if (vx>0) ani = CAnimations::GetInstance()->Get(500);
	else ani = CAnimations::GetInstance()->Get(501);

	ani->Render(x, y);
}

void CBrick::Render() {

	LPANIMATION ani = CAnimations::GetInstance()->Get(510);

	ani->Render(x, y);

}

void Yellow_Brick::Render() {

	LPANIMATION ani = CAnimations::GetInstance()->Get(520);

	ani->Render(x, y);

}

/*
void Door::Render() {
	LPANIMATION ani = CAnimation::GetInstance()->get(530);
	ani->Render(x, y);
}*/
void Floor ::Render() {

	LPANIMATION ani = CAnimations::GetInstance()->Get(540);

	ani->Render(x, y);

}

void Door::Render() {

	CAnimations::GetInstance()->Get(530) ->RenderFrame(x,y);
}



