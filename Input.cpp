#include "SDL.h"
#include "Input.h"
#include "Player.h"

void Input::init()
{
    up_press = false;
    down_press = false;
    left_press = false;
    right_press = false;
}

bool Input::checkForInput(Player* player)
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            return false;
        }

        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_UP: up_press = true; break;
                case SDLK_DOWN: down_press = true; break;
                case SDLK_LEFT: left_press = true; break;
                case SDLK_RIGHT: right_press = true; break;
            }
        }

        else if (event.type == SDL_KEYUP)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_UP: up_press = false; break;
                case SDLK_DOWN: down_press = false; break;
                case SDLK_LEFT: left_press = false; break;
                case SDLK_RIGHT: right_press = false; break;
            }
        }
    }

    if (up_press)
    {
        player->changeY(-1);
    }
    else if (down_press)
    {
        player->changeY(1);
    }
    if (left_press)
    {
        player->changeX(-1);
    }
    else if (right_press)
    {
        player->changeX(1);
    }

    return true;
}
