#include "render.h"

SDL_Renderer* initSDL(string name, int w, int h, SDL_Renderer* renderer) {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow(name.c_str(), 100, 100, w, h, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    return renderer;
}

SDL_Texture* createTexture(string file, SDL_Renderer* renderer) {

    SDL_Texture* texture;

    printf("Cargando %s...\n", file.c_str());

    texture = IMG_LoadTexture(renderer, file.c_str());
    return texture;

}

SDL_Texture* createLabel(string text, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer) {

    SDL_Surface* surface;
    SDL_Texture* texture;

    surface = TTF_RenderText_Blended(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    return texture;

}

void draw(SDL_Texture* texture, int x, int y, SDL_Renderer* renderer) {

    SDL_Rect dest;
    dest.x = x;
    dest.y = y;

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}