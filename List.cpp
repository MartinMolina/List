#include <iostream>
#include <fstream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "render.h"
#include "input.h"

using namespace std;

SDL_Renderer* renderer;
TTF_Font* mk4;
TTF_Font* mk4small;
TTF_Font* mkmyth;
SDL_Color fontColor = { 255, 255, 255 };
SDL_Texture* title;
SDL_Texture* character[8];
SDL_Texture* arrow;
SDL_Texture* instructions1;
SDL_Texture* instructions2;

InputState inputState;

fstream file;

int arrowHeight = 170;
int pos = 0;

bool appIsRunning = true;
bool flag = false;

void loadAssets() {

    string line;

    arrow = createTexture("assets/right-arrow.png", renderer);
    mk4 = TTF_OpenFont("assets/MK4.ttf", 100);
    mk4small = TTF_OpenFont("assets/MK4.ttf", 50);
    mkmyth = TTF_OpenFont("assets/mkmyth.ttf", 50);
    title = createLabel("LIST OF FIGHTERS", mk4, fontColor, renderer);
    for (int i = 0; i < 8; i++) {
        getline(file, line);
        character[i] = createLabel(line, mkmyth, fontColor, renderer);
    }
    instructions1 = createLabel("Usa las flechas para moverte por la lista", mk4small, fontColor, renderer);
    instructions2 = createLabel("Pulsa backspace para borrar un personaje", mk4small, fontColor, renderer);
}

void initializeApp() {
    file.open("assets/characters.cfg", ios::in);
    renderer = initSDL("Character list", 1300, 700, renderer);
    loadAssets();
    file.close();
}

void updateApp() {

    if (!flag) {

        if (inputState.up && pos > 0) {
            arrowHeight -= 50;
            flag = true;
            pos--;
        }

        if (inputState.down && pos < 7) {
            arrowHeight += 50;
            flag = true;
            pos++;
        }

    }
    else if (!inputState.up && !inputState.down)
        flag = false;

    if (inputState.backspace)
        character[pos] = createLabel(" ", mkmyth, fontColor, renderer);

    if (inputState.escape)
        appIsRunning = false;
}

void render() {
    int y = 150;
    SDL_RenderClear(renderer);
    draw(title, 10, 10, renderer);
    for (int i = 0; i < 8; i++) {
        draw(character[i], 70, y, renderer);
        y += 50;
    }
    draw(arrow, 35, arrowHeight, renderer);
    draw(instructions1, 10, 590, renderer);
    draw(instructions2, 10, 640, renderer);
    SDL_RenderPresent(renderer);
}

int main(int argc, char* args[])
{
    initializeApp();

    while (appIsRunning) {

        inputState = updateInput(inputState);
        updateApp();
        render();
        SDL_Delay(1000 / 60);
    }

    return 0;
}
