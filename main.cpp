#include "Game.h"

int main(int argc, char* args[])
{
    Game* game = new Game();

    while (game->checkForInput())
    {
        game->update();
    }

    delete game;

    return 0;
}
