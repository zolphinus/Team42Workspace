#include "GameController.h"

using std::cout;
using std::cin;
using std::endl;

GameController::GameController()
{

    makeHero();
    makeEnemies();

    startCurseStuff();
    messageWindow = new MessageWindow();
    mapReader = new MapReader("map0.txt");
    mapReader->PrintWindow(0, 0);
    message("TEST");
    moveHero();

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
    string userName;
    cout << "Please enter your name: ";
    cin >> userName;
    hero->setName(userName);

}

void GameController::randomHero(Character *&hero){
    hero = new Warrior();

    hero->generateChar();


}

void GameController::selectHero(Character *&hero){
    char menuSelector;
    bool jobSelected = false;

    while(jobSelected == false){

        cout << "What job will your hero be?" << endl;;
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
        default :
            cout << "PLEASE SELECT A JOB!!!" << endl;
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

    delete messageWindow;
    messageWindow = NULL;
    delete mapReader;
    mapReader = NULL;
    endwin();
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

void GameController::message(std::string newMessage){
    messageWindow->AddMessage(newMessage);
    messageWindow->PrintMessageWindow();
}



void GameController::startCurseStuff(){
    initscr();//-------------------------curses stuff
    cbreak();//--------------------------disables the buffer
    curs_set(0);//-----------------------makes cursor invisible
    start_color();//---------------------must be run before using color
    noecho();

}


void GameController::moveHero(){
    int ch;
    keypad(mapReader->getMapReader(), true);
    while(true){
    wmove(mapReader->getMapReader(), hero->getYPos(), hero->getXPos());
    waddch(mapReader->getMapReader(), 'P');
    ch = wgetch(mapReader->getMapReader());

    if( ch == KEY_DOWN){
        hero->setYPos(hero->getYPos() + 1);
        wclear(mapReader->getMapReader());
    }

    if( ch == KEY_UP){
        hero->setYPos(hero->getYPos() -1);
        wclear(mapReader->getMapReader());
    }

    if( ch == KEY_LEFT){
        hero->setXPos(hero->getXPos() - 1);
        wclear(mapReader->getMapReader());
    }

    if( ch == KEY_RIGHT){
        hero->setXPos(hero->getXPos() + 1);
        wclear(mapReader->getMapReader());
    }

    /*
    if( ch == KEY_UP){
        hero->setYPos(hero->getYPos() -1);
        wclear(mapReader->getMapReader());
    }

    if( ch == KEY_LEFT){
        hero->setXPos(hero->getXPos() - 1);
        wclear(mapReader->getMapReader());
    }

    if( ch == KEY_RIGHT){
        hero->setXPos(hero->getXPos() + 1);
        wclear(mapReader->getMapReader());
    }
    */



    mapReader->PrintWindow(hero->getYPos(), hero->getXPos());
    message("TEST");
    wrefresh(mapReader->getMapReader());
    }



}
