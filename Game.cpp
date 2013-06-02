#include "Game.h"
#include "Player.h"
#include "Input.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <sstream>

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    TTF_Init();

    SCREEN_WIDTH = 640;
    SCREEN_HEIGHT = 480;
    SCREEN_BPP = 32;

    screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);
    SDL_WM_SetCaption("Walk n' Shit",NULL);

    font = TTF_OpenFont("DejaVuSans.ttf",28);

    player = new Player(320,240,IMG_Load("Player.png"));
    input.init();

    tic = 0;

    text_color = {255,0,0};
    text_pos.x = 20;
    text_pos.y = 440;
}

Game::~Game()
{
    delete player;
    TTF_CloseFont(font);

    TTF_Quit();
    SDL_Quit();
}

void Game::update()
{
    if (player->getX() > SCREEN_WIDTH - player->getImage()->w)
    {
        player->setX(SCREEN_WIDTH - player->getImage()->w);
    }
    else if (player->getX() < 0)
    {
        player->setX(0);
    }
    if (player->getY() > SCREEN_HEIGHT - player->getImage()->h)
    {
        player->setY(SCREEN_HEIGHT - player->getImage()->h);
    }
    else if (player->getY() < 0)
    {
        player->setY(0);
    }
    draw();
}

bool Game::checkForInput()
{
    return input.checkForInput(player);
}

void Game::draw()
{
    SDL_Rect offset;
    offset.x = player->getX();
    offset.y = player->getY();
    std::stringstream ss;
    ss << "Updates: " << tic;

    SDL_Surface* message = TTF_RenderText_Solid(font,ss.str().c_str(),text_color);
    SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));

    SDL_BlitSurface(message,NULL,screen,&text_pos);

    SDL_BlitSurface(player->getImage(),NULL,screen,&offset);

    SDL_Flip(screen);

    tic++;

    SDL_Delay(10);
}
