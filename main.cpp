#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

using namespace std;

/// @brief
/// @param argc
/// @param argv
/// @return
int main(int argc, char *argv[])
{
    // // Print "Hello, World!" to the console
    // std::cout << "Hello, World!" << std::endl;
    // string poo;
    // cin >> poo;
    // std::cout << "Hi " << poo << std::endl;
    // string asd;
    // cin >> asd;
    // return 0;

    // >>>> SDL3 Setup
    // init sdl
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    // setup metadata
    SDL_SetAppMetadata("Omgine", "0.0.1", "com.eloisa.omgine");

    // create a window
    SDL_Window *window = SDL_CreateWindow(
        "Omgine",
        800,
        600,
        SDL_WINDOW_RESIZABLE);

    // Check that the window was successfully created
    if (window == NULL)
    {
        // In the case that the window could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    bool done = false;
    while (!done)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                done = true;
            }
        }

        // Do game logic, present a frame, etc.
    }

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // quit
    SDL_Quit();
    return 0;
}
