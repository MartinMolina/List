#pragma once
#include "SDL.h"

typedef struct InputState {
    bool up;
    bool down;
    bool backspace;
    bool escape;
};

InputState onKeyUp(int keyCode, InputState inputState);
InputState onKeyDown(int keyCode, InputState inputState);
InputState updateInput(InputState estadoInput);