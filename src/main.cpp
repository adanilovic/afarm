#include <stdio.h>
#include <SDL.h>
#include "SDL_image.h"
 
int main(int argc, char* argv[]) {

    SDL_Window * gwin = NULL;
    SDL_Renderer *gren = NULL;

    int ret = SDL_Init(SDL_INIT_EVERYTHING);

    if(!ret) {
        //success

        (void) IMG_Init(IMG_INIT_PNG);

        //Create an application window with the following settings:
        gwin = SDL_CreateWindow(
            "An SDL2 window",                  // window title
            SDL_WINDOWPOS_CENTERED,            // initial x position
            SDL_WINDOWPOS_CENTERED,            // initial y position
            640,                               // width, in pixels
            480,                               // height, in pixels
            SDL_WINDOW_SHOWN                   // flags - see below
        );

        if(gwin != NULL) {
            gren = SDL_CreateRenderer(gwin, -1, 0);
        }
    }
    else {
        fprintf(stderr, "SDL_Init(SDL_INIT_EVERYTHING): %s\n", SDL_GetError());
        return -1;
    }

    if(gren != NULL) {
        SDL_SetRenderDrawColor(gren, 0, 0, 0, 255);

        SDL_RenderClear(gren);

        SDL_RenderPresent(gren);

        SDL_Delay(5000);

        SDL_Quit();
    }

    return 0;
}
