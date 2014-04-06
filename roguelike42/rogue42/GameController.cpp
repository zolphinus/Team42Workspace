#include "GameController.h"

using std::cout;
using std::cin;
using std::endl;

GameController::GameController() : mapReader("map0.txt")
{
    makeHero();
    makeEnemies();
}

GameController::~GameController()
{
    cleanUp();
}


void GameController::makeHero(){

    char menuSelecter;
    cout << "Would you like to create a random hero? (Y/N)  ";
    cin >> menuSelecter;
    menuSelecter = toupper(menuSelecter);
    switch(menuSelecter){

        case 'Y':
            randomHero(hero);
            break;

        default :
            selectHero(hero);
    }

}

void GameController::randomHero(Character *&hero){
    hero = new Warrior();

    hero->generateChar();

}

void GameController::selectHero(Character *&hero){
    char menuSelector;
    bool jobSelected = false;

    while(jobSelected == false){

        cout << "What job will your hero be?" << endl;
        cout << "W - Warrior" << endl;
        cout << "H - Healer" << endl;

        cin >> menuSelector;
        menuSelector = toupper(menuSelector);
        switch(menuSelector){

        case 'W':
            hero = new Warrior();
            jobSelected = true;
            break;
        case 'H':
            hero = new Healer();
            jobSelected = true;
            break;
        }
    }
    hero->generateChar();
}

Character* GameController::getHero(){
    return hero;
}

void GameController::makeEnemies(){

    if(enemy.size() != 0){
        for( int i = 0; i < enemy.size(); i++)
        {
            randomEnemy(enemy[i]);
            enemy[i]->generateChar();
            cout << endl << "MADE :" << enemy[i]->getName()  << endl; //
        }
    }
}

void GameController::randomEnemy(Enemy*& newEnemy){
    //INCREASE THIS MOD VALUE AS YOU ADD ENEMY TYPES TO FUNCTION
    int temp = rand() % 1;

    //BE SURE TO USE INT VALUES AND NOT CHAR
    switch(temp){
    case 0:
        newEnemy = new Slime();
        break;
    }
}

void GameController::cleanUp(){

    delete hero;
    if(enemy.size() != 0){
        for( int i = 0; i < enemy.size(); i++)
        {
            delete enemy[i];
        }
    }

    enemy.resize(0);
}

/*

    GameController();
    ~GameController();
    void heroTurn();
    void enemyTurns();
    void makeMoves();
    void fight();
    //void updateGameState(character&);
    void makeHero();
    Character* hero;

    */

void GameController::moveHero(){
    hero->setYPos(0);
    hero->setXPos(0);



}
