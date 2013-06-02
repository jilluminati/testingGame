#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Player.h"
#include "Input.h"
#include "SDL.h"
#include "SDL_Image.h"
#include "SDL_ttf.h"

class Game
{
private:
    Player* player;
    Input input;
    TTF_Font* font;
    SDL_Surface* screen;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    int SCREEN_BPP;
    int tic;
    SDL_Color text_color;
    SDL_Rect text_pos;
public:
    Game();
    ~Game();
    bool checkForInput();
    void draw();
    void update();
};

#endif // GAME_H_INCLUDED
