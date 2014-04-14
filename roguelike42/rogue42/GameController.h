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
    void runGame();
    void heroTurn();
    void enemyTurns();
    void fight();
    void updateGameState();
    void randomEnemy(Enemy*&);
    void assignRandomLocation(Character*&);
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
    void generateLocation(Character*);
    void makeMoves(Character*, int);
    Character* findCharacter(int y, int x);

    void moveBoulder(int yPos, int xPos, int direction);

    int floorsCleared;

};




#endif // GAME_CONTROLLER_H
