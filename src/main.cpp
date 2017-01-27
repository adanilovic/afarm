#include <stdio.h>
#include <SDL.h>
#include "SDL_image.h"
 
int main(int argc, char* argv[]) {

    SDL_Window * gwin = NULL;
    SDL_Renderer *gren = NULL;

    SDL_Rect mSource;
    SDL_Rect mDest;

    int ret = SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Surface *img;

    if(!ret) {
        //success

        (void) IMG_Init(IMG_INIT_PNG);

        img = IMG_Load("../res/Big_Green.png");
        if(!img) {
            printf("AD - image didn't load\n");
        }
        else {

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
    }
    else {
        fprintf(stderr, "SDL_Init(SDL_INIT_EVERYTHING): %s\n", SDL_GetError());
        return -1;
    }

    if(gren != NULL) {

        SDL_Texture* text = SDL_CreateTextureFromSurface(gren, img);

        SDL_FreeSurface(img);       

        SDL_QueryTexture(text, NULL, NULL, &mSource.w, &mSource.h);
        mDest.x = mSource.x = 0;
        mDest.y = mSource.y = 0;
        mDest.w = mSource.w;
        mDest.h = mSource.h;

        SDL_SetRenderDrawColor(gren, 0, 0, 0, 255);

        SDL_RenderClear(gren);

        SDL_RenderCopy(gren, text, &mSource, &mDest);

        SDL_RenderPresent(gren);

        SDL_Delay(5000);

        SDL_Quit();

        IMG_Quit();
    }

    return 0;
}
