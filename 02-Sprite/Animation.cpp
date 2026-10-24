#include "Animation.h"
void CAnimation::Add(int spriteId, DWORD time)
{
	int t = time;
	if (time == 0) t = this->defaultTime;

	LPSPRITE sprite = CSprites::GetInstance()->Get(spriteId);
	LPANIMATION_FRAME frame = new CAnimationFrame(sprite, t);
	frames.push_back(frame);
}

void CAnimation::Render(float x, float y)
{
	ULONGLONG now = GetTickCount64();
	if (currentFrame == -1)
	{
		currentFrame = 0;
		lastFrameTime = now;
	}
	else
	{
		DWORD t = frames[currentFrame]->GetTime();
		if (now - lastFrameTime > t)
		{
			currentFrame++;
			lastFrameTime = now;
			if (currentFrame == frames.size()) currentFrame = 0;
			//DebugOut(L"now: %d, lastFrameTime: %d, t: %d\n", now, lastFrameTime, t);
		}

	}
	
	frames[currentFrame]->GetSprite()->Draw(x, y);	
}

void CAnimation::AddFrame(vector<int> spriteID, DWORD time) {
	int t = time;
	if (time == 0) {
		t = this -> defaultTime;
	}
	vector<LPSPRITE>sprites;
	for (int id : spriteID)
	{
		LPSPRITE sprite = CSprites::GetInstance()->Get(id);
		sprites.push_back(sprite);
	}
	LPANIMATION_FRAME frame = new CAnimationFrame(sprites, t);
	frames.push_back(frame);
}

void CAnimation::RenderFrame(float x, float y) {
	ULONGLONG now = GetTickCount64();
	if (currentFrame == -1)
	{
		currentFrame = 0;
		lastFrameTime = now;
	}
	else
	{
		DWORD t = frames[currentFrame]->GetTime();
		if (now - lastFrameTime > t)
		{
			currentFrame++;
			lastFrameTime = now;
			if (currentFrame == frames.size()) currentFrame = 0;
			//DebugOut(L"now: %d, lastFrameTime: %d, t: %d\n", now, lastFrameTime, t);
		}

	}
	vector<LPSPRITE> sprites = frames[currentFrame]->GetSprites();
	for (int i = 0; i < sprites.size() -1; i++)
	{
		sprites[i]->Draw(x, y); //
		sprites[++i]->Draw(x, y + 16);
	}
}