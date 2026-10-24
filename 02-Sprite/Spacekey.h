#pragma once
#include <dinput.h>

#include "keyboardstate.h"

class CSpaceKeyHandler : public CKeyEventHandler
{
    void KeyState(BYTE* states) override;
    void OnKeyDown(int KeyCode) override;
    void OnKeyUp(int KeyCode) override;
   
};

