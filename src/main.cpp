#include <stdio.h>

#include <SDL.h>
 
class CApp {
 
    public:
 
        CApp();
 
        int OnExecute();
 
};

CApp::CApp() {
}
 
int CApp::OnExecute() {
    return 0;
}
 
int main(int argc, char* argv[]) {
    CApp theApp;

    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
 
    return theApp.OnExecute();
}
