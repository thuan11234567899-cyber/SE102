#pragma once
#include <dinput.h>

#include "keyboardstate.h"

class CTankKeyHandler : public CKeyEventHandler
{
    void KeyState(BYTE* states) override;
    void OnKeyDown(int KeyCode) override;
    void OnKeyUp(int KeyCode) override;
};
