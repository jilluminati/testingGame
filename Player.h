#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "SDL.h"
class Player
{
private:
    int x;
    int y;
    SDL_Surface* image;
public:
    Player(int xn, int yn, SDL_Surface* imagen);
    ~Player();
    int getX();
    int getY();
    SDL_Surface* getImage();
    void changeX(int dx);
    void changeY(int dy);
    void setX(int xnew);
    void setY(int ynew);
};


#endif // PLAYER_H_INCLUDED
