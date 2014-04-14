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
    void updateGameState();
    void randomEnemy(Enemy*&);
    void assignRandomLocation(Character*&);
    void runGame();
    void screenTestDriver();

    void message(std::string);
    void move(Character*); //conceptual
    Character* getHero();

private:
    bool isPlaying;
    Character* hero;
    std::vector <Enemy*> enemy;
    std::vector <Item*> item;
    MapReader* mapReader;
    MessageWindow* messageWindow;
    StatsWindow* statusWindow;

    void makeHero();
    void makeEnemies();
    void startCurseStuff();
    void randomHero(Character*&);
    void selectHero(Character*&);
    void cleanUp();
    void updateMap(int y, int x);
    void heroDead();
    void winGame();


    int floorsCleared;

};




#endif // GAME_CONTROLLER_H
