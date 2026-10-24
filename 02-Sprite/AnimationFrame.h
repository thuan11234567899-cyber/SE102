#pragma once

#include "Sprite.h"

/*
	Sprite animation
*/
class CAnimationFrame
{
	LPSPRITE sprite;
	vector<LPSPRITE> sprites;
	DWORD time;

public:
	CAnimationFrame(LPSPRITE sprite, int time) { this->sprite = sprite; this->time = time; }

	CAnimationFrame(vector<LPSPRITE> sprites, int time) { this->sprites = sprites; this->time = time; } // sửa thành vector
	DWORD GetTime() { return time; }
	LPSPRITE GetSprite() { return sprite; }
	vector<LPSPRITE> GetSprites() { return sprites; } // sửa thành 1 vector 
};

typedef CAnimationFrame* LPANIMATION_FRAME;

