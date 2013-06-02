#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "SDL.h"
#include "Player.h"

class Input
{
private:
    SDL_Event event;
    bool down_press;
    bool up_press;
    bool left_press;
    bool right_press;
public:
    bool checkForInput(Player* player);
    void init();

};


#endif // INPUT_H_INCLUDED
