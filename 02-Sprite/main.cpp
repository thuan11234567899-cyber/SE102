/* =============================================================
	INTRODUCTION TO GAME PROGRAMMING SE102
	
	SAMPLE 02 - SPRITE AND ANIMATION

	This sample illustrates how to:

		1/ Render a sprite (within a sprite sheet)
		2/ How to manage sprites/animations in a game
		3/ Enhance CGameObject with sprite animation
================================================================ */

#include <Windows.h>
#include <d3d10.h>
#include <d3dx10.h>

#include "debug.h"
#include "Game.h"
#include "Textures.h"

#include "Sprite.h"
#include "Sprites.h"

#include "Animation.h"
#include "Animations.h"

#include "Mario.h"
#include "Tank.h"
#include "keyboardstate.h"
#include "tankkey.h"

#include "Spacekey.h"
#include "Space.h"
#include "Bullet.h"
#include "EnemyManager.h"

#include <vector>

#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"02 - Sprite animation"
#define WINDOW_ICON_PATH L"mario.ico"

#define BACKGROUND_COLOR D3DXCOLOR(0.0f,0.0f,0.0f ,0.0f)
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define ID_TEX_MARIO 0
#define ID_TEX_ENEMIES 10
#define ID_TEX_MISC 20
#define ID_TEX_Tank 30
#define ID_TEX_SPACE 40

#define TEXTURES_DIR L"textures"
#define TEXTURE_PATH_MARIO TEXTURES_DIR "\\mario.png"
#define TEXTURE_PATH_MISC TEXTURES_DIR "\\misc_transparent.png"
#define TEXTURE_PATH_ENEMIES TEXTURES_DIR "\\enemies.png"
#define TEXTURE_PATH_TANK TEXTURES_DIR "\\tank1.png"
#define TEXTURE_PATH_SPACE TEXTURES_DIR "\\space.png"


CMario *mario;
#define MARIO_START_X 10.0f
#define MARIO_START_Y 130.0f
#define MARIO_START_VX 0.1f

#define SPACE_START_X 10.0f
#define SPACE_START_Y 10.0f
#define SPACE_START_VX 0.1f

CBrick *brick;

Yellow_Brick* ybrick;
Door* door;
Floor* roof;
Tank* tank;

Enemies* enemies;
CSpace* space;
CSpaceKeyHandler* spaceKey;
vector <Bullet*> bullets;


LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

/*
	Load all game resources 
	In this example: load textures, sprites, animations and mario object
*/
void LoadResources()
{
	CTextures * textures = CTextures::GetInstance();

	textures->Add(ID_TEX_MARIO, TEXTURE_PATH_MARIO);
	textures->Add(ID_TEX_ENEMIES, TEXTURE_PATH_ENEMIES);
	textures->Add(ID_TEX_Tank, TEXTURE_PATH_TANK);
	//textures->Add(ID_ENEMY_TEXTURE, TEXTURE_PATH_ENEMIES, D3DCOLOR_XRGB(156, 219, 239));
	textures->Add(ID_TEX_MISC, TEXTURE_PATH_MISC);
	textures->Add(ID_TEX_SPACE, TEXTURE_PATH_SPACE);

	CSprites * sprites = CSprites::GetInstance();
	
	LPTEXTURE texMario = textures->Get(ID_TEX_MARIO);

	// readline => id, left, top, right, bottom

	sprites->Add(10001, 246, 154, 259, 181, texMario);
	sprites->Add(10002, 275, 154, 290, 181, texMario);
	sprites->Add(10003, 304, 154, 321, 181, texMario);

	sprites->Add(10011, 186, 154, 200, 181, texMario);
	sprites->Add(10012, 155, 154, 171, 181, texMario);
	sprites->Add(10013, 125, 154, 141, 181, texMario);

	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;

	ani = new CAnimation(100);
	ani->Add(10001);
	ani->Add(10002);
	ani->Add(10003);
	animations->Add(500, ani);



	ani = new CAnimation(100);
	ani->Add(10011);
	ani->Add(10012);
	ani->Add(10013);
	animations->Add(501, ani);



	LPTEXTURE texMisc = textures->Get(ID_TEX_MISC);
	sprites->Add(20001, 300, 117, 317, 133, texMisc);
	sprites->Add(20002, 318, 117, 335, 133, texMisc);
	sprites->Add(20003, 336, 117, 353, 133, texMisc);
	sprites->Add(20004, 354, 117, 371, 133, texMisc);

	ani = new CAnimation(100);
	ani->Add(20001,1000);
	ani->Add(20002);
	ani->Add(20003);
	ani->Add(20004);
	animations->Add(510, ani);

	// yellow brick
	sprites->Add(30001, 300, 117 + 18, 317 , 133 + 18, texMisc);
	sprites->Add(30002, 318, 117 + 18, 335 , 133 + 18, texMisc);
	sprites->Add(30003, 336, 117 + 18, 353 , 133 + 18, texMisc);
	sprites->Add(30004, 354, 117 + 18 ,371 , 133 + 18, texMisc);
	

	ani = new CAnimation(100);
	ani->Add(30001, 1000);
	ani->Add(30002);
	ani->Add(30003);
	ani->Add(30004);
	animations->Add(520, ani);

	// Floor 
	sprites->Add(30011, 336, 154, 351, 168, texMisc);
	sprites->Add(30012, 336, 154, 351, 168, texMisc);
	sprites->Add(30013, 336, 154, 351, 168, texMisc);
	sprites->Add(30014, 336, 154, 351, 168, texMisc);



	ani = new CAnimation(100);
	ani->Add(30011, 1000);
	ani->Add(30012);
	ani->Add(30013);
	ani->Add(30014);
	animations->Add(540, ani);
	// Door 
	sprites->Add(40001, 294,  225 , 297, 240, texMisc);
	sprites->Add(40002, 294,  207 , 297, 222, texMisc);
	sprites->Add(40003, 290,  189 , 297, 204, texMisc);
	sprites->Add(40004, 290,  170 , 297, 186, texMisc);
	sprites->Add(40005, 285,  153 , 297, 168, texMisc);
	sprites->Add(40006, 285,  135 , 297, 150, texMisc);
	sprites->Add(40007, 282,  117 , 297, 132, texMisc);
	sprites->Add(40008, 282,  99  , 297, 114, texMisc);

	ani = new CAnimation(100);
	ani->AddFrame({40002,40001});
	ani->AddFrame({40004,40003 });
	ani->AddFrame({40006,40005 });
	ani->AddFrame({40008,40007 });
	animations->Add(530, ani);

	

	// space 
	LPTEXTURE texSpace = textures->Get(ID_TEX_SPACE);
	sprites->Add(60001, 24, 9, 47, 21, texSpace);
	ani = new CAnimation(100);
	ani->Add(60001);
	animations->Add(ID_ANI_SPACE, ani);
	space = new CSpace(SPACE_START_X + 20 , SPACE_START_Y+ 20);
	spaceKey = new CSpaceKeyHandler();

	// Bullet
	sprites->Add(60002, 249, 10, 254, 21, texSpace);
	ani = new CAnimation(100);
	ani->Add(60002);
	animations->Add(ID_ANI_Bullet, ani);
	

	// enemy
	LPTEXTURE texEnemy = textures->Get(ID_TEX_ENEMIES);
	sprites->Add(70001,3, 820,21, 836  ,texEnemy);
	ani = new CAnimation(100);
	ani->Add(70001);
	animations->Add(ID_ANI_ENEMY, ani);
	enemies = new Enemies();
	
	
	mario  = new CMario(MARIO_START_X, MARIO_START_Y +10, MARIO_START_VX);
	//brick  = new CBrick(100.0f, 100.0f);
	//ybrick = new Yellow_Brick(150.0f, 100.0f);
	//roof   = new Floor(10.0f,150.0f);
	//door   = new Door(295.0f, 118.0f);
	//tank = new Tank(200.0f, 100.0f);
	
}

/*
	Update world status for this frame
	dt: time period between beginning of last frame and beginning of this frame
*/
void Update(DWORD dt)
{
	mario->Update(dt);
	space->Update(dt);
	for (auto bullet : bullets) {
		bullet->Update(dt);
	}
	enemies->Update(dt);
	
}

void Render()
{
	CGame* g = CGame::GetInstance();

	ID3D10Device* pD3DDevice = g->GetDirect3DDevice();
	IDXGISwapChain* pSwapChain = g->GetSwapChain();
	ID3D10RenderTargetView* pRenderTargetView = g->GetRenderTargetView();
	ID3DX10Sprite* spriteHandler = g->GetSpriteHandler();

	if (pD3DDevice != NULL)
	{
		// clear the background 
		pD3DDevice->ClearRenderTargetView(pRenderTargetView, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DX10_SPRITE_SORT_TEXTURE);
		
		// Use Alpha blending for transparent sprites
		FLOAT NewBlendFactor[4] = { 0,0,0,0 };
		pD3DDevice->OMSetBlendState(g->GetAlphaBlending(), NewBlendFactor, 0xffffffff);

		// bullet fire
		for (auto bullet : bullets) {
			bullet->Render();
		}
		// Spaceship go 
		space->Render();

		// Enemy 
		enemies->Render();
		// Uncomment this line to see how to draw a porttion of a texture  
		//g->Draw(10, 10, texMisc, 300, 117, 316, 133);


		spriteHandler->End();
		pSwapChain->Present(0, 0);
	}
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = (HICON)LoadImage(hInstance, WINDOW_ICON_PATH, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			MAIN_WINDOW_TITLE,
			WS_OVERLAPPEDWINDOW, // WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);

	if (!hWnd)
	{
		DWORD ErrCode = GetLastError();
		DebugOut(L"[ERROR] CreateWindow failed! ErrCode: %d\nAt: %s %d \n", ErrCode, _W(__FILE__), __LINE__);
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	SetDebugWindow(hWnd);

	return hWnd;
}

int Run()
{
	CGame* game = CGame::GetInstance();
	MSG msg;
	int done = 0;
	ULONGLONG frameStart = GetTickCount64();
	ULONGLONG tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		ULONGLONG now = GetTickCount64();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		ULONGLONG dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;
			game->ProcessKeyboard();
			Update((DWORD)dt);
			Render();
		}
		else
			Sleep((DWORD)(tickPerFrame - dt));
	}

	return 1;
}

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
) {
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	CGame *game = CGame::GetInstance();
	game->Init(hWnd, hInstance);

	LoadResources();
	game->InitKeyboard(spaceKey);

	SetWindowPos(hWnd, 0, 0, 0, SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);

	Run();

	return 0;
}