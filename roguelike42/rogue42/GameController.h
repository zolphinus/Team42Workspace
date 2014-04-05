#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Character.h"
#include "MapRead.h"

class Character;

class GameController{

public:
    GameController();
    ~GameController();
    void heroTurn();
    void enemyTurns();
    void makeMoves();
    void fight();
    //void updateGameState(character&);
    void makeHero();
    void randomHero(Character*&);
    void selectHero(Character*&);
    Character* getHero();

private:
    Character* hero;
    //spot for MapReader Object
    //spot for status window
    bool playingGame;
    int floorsCleared;

};




#endif // GAME_CONTROLLER_H
