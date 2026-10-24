#include "TankKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Tank.h"

extern Tank* tank;

void CTankKeyHandler::OnKeyDown(int KeyCode)
{
	
}

void CTankKeyHandler::OnKeyUp(int KeyCode)
{
	
}

void CTankKeyHandler::KeyState(BYTE* states)
{
    CGame* game = CGame::GetInstance();

    DebugOut(L"[INFO] Tank KeyState called\n");

    if (tank == NULL)
        return;

    if (game->IsKeyDown(DIK_W))
        tank->move(0, -1);
    else if (game->IsKeyDown(DIK_S))
        tank->move(0, 1);
    else if (game->IsKeyDown(DIK_A))
        tank->move(-1, 0);
    else if (game->IsKeyDown(DIK_D))
        tank->move(1, 0);
}