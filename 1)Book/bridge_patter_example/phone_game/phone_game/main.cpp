#include <iostream>
#include "BridgePattern.h"

int main()
{
    Game *game;
    Phone *phone;

    // Новый телефон марки PhoneA , захотели сыграть в игру A
    phone = new PhoneA();
    game = new GameA();
    phone->setupGame(game);
    phone->play();
    printf("++++++++++++++++++++++++++++++++++\n");

    //  сыграть в игру B на этом телефоне
    delete game;
    game = new GameB();
    phone->setupGame(game);
    phone->play();

    delete phone;
    delete game;

    
    return 0;
}
