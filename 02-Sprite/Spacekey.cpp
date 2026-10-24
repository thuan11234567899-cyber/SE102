#include "spacekey.h"

#include "debug.h"
#include "Game.h"
#include <vector>

#include "Space.h"
#include "Bullet.h"
extern CSpace* space;
extern vector <Bullet*> bullets;
// bullet fire 
void CSpaceKeyHandler::OnKeyDown(int KeyCode)
{
    if (KeyCode == DIK_SPACE && space != nullptr)
    {
        Bullet* bullet = new Bullet (space->GetX() + 15, space->GetY()
        );
         
        bullets.push_back(bullet);
    }
}

void CSpaceKeyHandler::OnKeyUp(int KeyCode)
{
    // Xử lý khi thả phím
}

void CSpaceKeyHandler::KeyState(BYTE* states)
{
    if (space == NULL)
        return;

    float vx = 0.0f;
    float vy = 0.0f;
    float speed = 0.1f;

    if (states[DIK_W] & 0x80)
        vy += -speed;
    else if (states[DIK_S] & 0x80)
        vy += speed;
    else if (states[DIK_A] & 0x80)
        vx += -speed;
    else if (states[DIK_D] & 0x80)
        vx += speed;

    space->Setstate(vx, vy);
}   

