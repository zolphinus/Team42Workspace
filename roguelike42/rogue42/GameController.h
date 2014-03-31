#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Character.h"
#include "MapRead.h"

class GameController{

public:
    GameController();
    ~GameController();


private:
    Character* hero;


};


GameController::GameController()
{
    hero = new Character;
}

~GameController::GameController()
{
    delete hero;
}


#endif // GAME_CONTROLLER_H
