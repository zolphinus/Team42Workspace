#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Character.h"
#include "MapReader.h"
#include <vector>
#include "MessageWindow.h"
#include <string>
#include "StatsWindow.h"
#include "GameConfig.h"

class Character;

class GameController{

public:
    GameController();
    ~GameController();
    void runGame();
    void screenTestDriver();
    void message(std::string);


    Character* getHero();

private:
    int itemNum;
    int enemyNum;
    bool isPlaying;
    Character* hero;
    std::vector <Enemy*> enemy;
    std::vector <Item*> item;
    MapReader* mapReader;
    MessageWindow* messageWindow;
    StatsWindow* statusWindow;

    void makeHero();
    void makeEnemies();
    void makeItems();
    void initGame();
    void startCurseStuff();
    void randomHero(Character*&);
    void selectHero(Character*&);
    void heroTurn();
    void enemyTurns();

    void itemEnemyReset();
    void cleanUpGame();
    void move(Character*);
    void fight();
    void updateGameState(Character*);
    void randomEnemy(Enemy*&);
    void randomItem(Item*& newItem);
    void assignRandomLocation(Character*&);
    void updateMap(int y, int x);
    void heroDead();
    void winGame();
    void generateLocation(Character*);
    void genLocations();
    void makeMoves(Character*, int);
    Character* findCharacter(int y, int x);
    Item* findItem(int y, int x);
    void genItemLocations();
    void generateLocation(Item*);
    void moveBoulder(int yPos, int xPos, int direction);
    void goDownstairs(int, int);
    int floorsCleared;

};




#endif // GAME_CONTROLLER_H
