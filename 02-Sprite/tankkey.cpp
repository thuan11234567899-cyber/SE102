#include "tankkey.h"

#include "debug.h"
#include "Game.h"

#include "tank.h"

extern Tank* tank;

void CTankKeyHandler::OnKeyDown(int KeyCode)
{

}

void CTankKeyHandler::OnKeyUp(int KeyCode)
{

}

void CTankKeyHandler::KeyState(BYTE* states)
{
    if (tank == NULL)
        return;

    if (states[DIK_W] & 0x80)
        tank->move(0, -5);
    else if (states[DIK_S] & 0x80)
        tank->move(0, 5);
    else if (states[DIK_A] & 0x80)
        tank->move(-5, 0);
    else if (states[DIK_D] & 0x80)
        tank->move(5, 0);
}