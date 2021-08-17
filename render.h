#pragma once
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

using namespace std;

SDL_Renderer* initSDL(string name, int w, int h, SDL_Renderer* renderer);
SDL_Texture* createTexture(string file, SDL_Renderer* renderer);
SDL_Texture* createLabel(string text, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer);
void draw(SDL_Texture* texture, int x, int y, SDL_Renderer* renderer);