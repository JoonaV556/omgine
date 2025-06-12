#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <filesystem>

using namespace std;

/*
Showcase of rendering a simple texture
1. load from file
2. render on screen
Also good showcase of SDL error handling / logging
*/

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

/// @brief
/// @param argc
/// @param argv
/// @return
int main(int argc, char *argv[])
{
    // >>>> SDL3 Setup
    // init sdl
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    // setup metadata
    SDL_SetAppMetadata("Omgine", "0.0.1", "com.eloisa.omgine");

    // rendering sutff
    SDL_Window *window = NULL;   // window is a window
    SDL_Renderer *rend = NULL;   //
    SDL_Surface *surface = NULL; // pixel data for manipulation on cpu
    SDL_Texture *texture = NULL; // pixel data feeded to gpu

    // create window & renderer
    if (!SDL_CreateWindowAndRenderer("DrawTexture", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &rend))
    {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return 1;
    }

    SDL_LogDebug(SDL_LOG_CATEGORY_TEST, "poopyy");

    // load image into surface
    SDL_LogDebug(SDL_LOG_CATEGORY_TEST, "%s", std::filesystem::current_path().string().c_str());
    const char *imgPath = "assets/images/blue.png";
    surface = IMG_Load(imgPath);
    if (!surface)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "IMG_Load failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // poopy
    SDL_SetDefaultTextureScaleMode(rend, SDL_SCALEMODE_NEAREST);

    // create texture for gpu
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST); // :))
    texture = SDL_CreateTextureFromSurface(rend, surface);

    if (!texture)
    {
        SDL_Log("Couldn't create static texture: %s", SDL_GetError());
        return 1;
    }

    float textureScale = 10.0f;
    SDL_FRect rect;
    rect.x = 0.0f;
    rect.y = 0.0f;
    rect.w = (float)surface->w * textureScale;
    rect.h = (float)surface->h * textureScale;

    SDL_DestroySurface(surface); /* done with this, the texture has a copy of the pixels now. */

    // render texture
    /* as you can see from this, rendering draws over whatever was drawn before it. */
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 254); /* black, full alpha */
    SDL_RenderClear(rend);                      /* start with a blank canvas. */
    SDL_RenderTexture(rend, texture, nullptr, &rect);
    SDL_RenderPresent(rend); /* put it all on the screen! */

    // main loop
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
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);

    // quit
    SDL_Quit();
    return 0;
}
