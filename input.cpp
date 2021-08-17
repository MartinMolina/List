#include "input.h"


InputState onKeyUp(int keyCode, InputState inputState) {

    if (keyCode == SDLK_UP) {
        inputState.up = false;
    }
    else if (keyCode == SDLK_DOWN) {
        inputState.down = false;
    }

    if (keyCode == SDLK_BACKSPACE) {
        inputState.backspace = false;
    }

    if (keyCode == SDLK_ESCAPE) {
        inputState.escape = false;
    }

    return inputState;
}

InputState onKeyDown(int keyCode, InputState inputState) {

    if (keyCode == SDLK_UP) {
        inputState.up = true;
        inputState.down = false;
    }
    else if (keyCode == SDLK_DOWN) {
        inputState.up = false;
        inputState.down = true;
    }

    if (keyCode == SDLK_BACKSPACE) {
        inputState.backspace = true;
    }

    if (keyCode == SDLK_ESCAPE) {
        inputState.escape = true;
    }

    return inputState;
}

InputState updateInput(InputState inputState) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            exit(0);
            break;

        case SDL_KEYUP:
            inputState = onKeyUp(event.key.keysym.sym, inputState);
            break;

        case SDL_KEYDOWN:
            inputState = onKeyDown(event.key.keysym.sym, inputState);
            break;

        default:
            break;
        }
    }
    return inputState;
}