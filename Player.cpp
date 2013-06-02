#include "SDL.h"
#include "SDL_image.h"
#include "Player.h"

Player::Player(int xn, int yn, SDL_Surface* imagen)
{
    x = xn;
    y = yn;
    image = imagen;
}

Player::~Player()
{
    SDL_FreeSurface(image);
}

int Player::getX()
{
    return x;
}

int Player::getY()
{
    return y;
}

SDL_Surface* Player::getImage()
{
    return image;
}

void Player::changeX(int dx)
{
    x += dx;
}

void Player::changeY(int dy)
{
    y += dy;
}

void Player::setX(int xnew)
{
    x = xnew;
}

void Player::setY(int ynew)
{
    y = ynew;
}
