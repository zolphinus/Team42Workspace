#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Character.h"
#include "MapReader.h"
#include <vector>
#include "MessageWindow.h"
#include <string>
#include "StatsWindow.h"

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
    void makeEnemies();
    void randomEnemy(Enemy*&);
    void randomHero(Character*&);
    void selectHero(Character*&);

    void message(std::string);
    void moveHero(); //conceptual
    void cleanUp();
    Character* getHero();

private:
    Character* hero;
    std::vector <Enemy*> enemy;
    MapReader* mapReader;
    MessageWindow* messageWindow;
    StatsWindow* statusWindow;
    void startCurseStuff();

    bool playingGame;
    int floorsCleared;

};




#endif // GAME_CONTROLLER_H
