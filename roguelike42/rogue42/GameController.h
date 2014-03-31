#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Character.h"
#include "MapRead.h"

class GameController{

public:
    GameController();
    ~GameController();
    void heroTurn();
    void enemyTurns();
    void makeMoves();
    void fight();
    void updateGameState(character&);


private:
    Character* hero;
    //spot for MapReader Object
    //spot for status window
    bool playingGame;
    int floorsCleared;

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
