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

    //Prepares the message window for display
    message("");

    statusWindow = new StatsWindow();
    statusWindow->PrintStatsWindow(hero);
    isPlaying = true;

    hero->setYPos(3);
    hero->setXPos(8);
    wmove(mapReader->getMapReader(), hero->getYPos(), hero->getXPos());
    mapReader->PrintWindow(hero->getYPos(), hero->getXPos());
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
    cout << userName << endl;
    if (userName.length() > 10)
    {
        userName.resize(10);
    }
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
    delete statusWindow;
    statusWindow = NULL;
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

    //Fixed Position to display character in window.
    wmove(mapReader->getMapReader(), 8, 25);
    waddch(mapReader->getMapReader(), 'P');


    ch = wgetch(mapReader->getMapReader());
    string temp = "";

    if( ch == KEY_DOWN){

        if(mapReader->atPosition(hero->getYPos()+1, hero->getXPos()) != '#')
        {
            hero->setYPos(hero->getYPos() + 1);
            wclear(mapReader->getMapReader());
        }
    }

    if( ch == KEY_UP){
        if(mapReader->atPosition(hero->getYPos()-1, hero->getXPos()) != '#'){
            hero->setYPos(hero->getYPos() -1);
            wclear(mapReader->getMapReader());
        }
    }

    if( ch == KEY_LEFT){
        if(mapReader->atPosition(hero->getYPos(), hero->getXPos() - 1) != '#'){
            hero->setXPos(hero->getXPos() - 1);
            wclear(mapReader->getMapReader());
        }
    }

    if( ch == KEY_RIGHT){
        if(mapReader->atPosition(hero->getYPos(), hero->getXPos() + 1) != '#'){
            hero->setXPos(hero->getXPos() + 1);
            wclear(mapReader->getMapReader());
        }
    }

    if ( ch == '<'){
        message("TRY TO GO DOWNSTAIRS");
    }

    if ( ch == '>'){
        message("TRY TO GO UPSTAIRS");
    }

    if ( ch == 'p' || ch == 'P')
    {
        message("PICKUP ITEM");
    }

    if ( ch == 'e' || ch == 'E')
    {
        message("EQUIP STUFF");
    }

    if ( ch == 's' || ch == 'S'){
        message("SPECIAL ATTACK");
    }

}


void GameController::updateMap(int y, int x){
    mapReader->PrintWindow(y, x);
    wrefresh(mapReader->getMapReader());
}

void GameController::runGame(){
    while(isPlaying == true)
    {
        moveHero();
        updateGameState();
    }
}

void GameController::updateGameState(){
    updateMap(hero->getYPos(), hero->getXPos());
    statusWindow->PrintStatsWindow(hero);

    hero->setCurHP(hero->getCurHP() - 1);
    if(hero->getCurHP() < 0)
    {
        heroDead();
    }

}

void GameController::heroDead(){
    //isPlaying = false;
    message("So yeah, you kinda died, how lame...");
}
