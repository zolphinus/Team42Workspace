#include "GameController.h"
#include <string>
#include "Character.h"

using std::cout;
using std::cin;
using std::endl;




GameController::GameController()
{
    srand(time(NULL));
    enemyNum = rand() % 10 + 3;
    itemNum = rand() % 10 + 3;
    makeHero();

    startCurseStuff();
    messageWindow = new MessageWindow();
    mapReader = new MapReader("map0.txt",itemNum,enemyNum);
    enemy.resize(enemyNum);
    item.resize(itemNum);
    makeEnemies();

    //Prepares the message window for display
    message("");

    statusWindow = new StatsWindow();
    statusWindow->PrintStatsWindow(hero);
    isPlaying = true;
    floorsCleared = 0;

    wmove(mapReader->getMapReader(), hero->getYPos(), hero->getXPos());
    mapReader->PrintWindow(hero->getYPos(), hero->getXPos(), enemy, item);

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
    generateLocation(hero);
}

void GameController::randomHero(Character *&hero){
    //Should use enumerated types here


    int pickRandom = rand() % 2;

    switch(pickRandom)
    {
    case 0:
        hero = new Warrior();
        break;
    case 1:
        hero = new Healer();
    }

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
            enemy[i]->setYPos(7);
            enemy[i]->setXPos(7);
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

    generateLocation(newEnemy);

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


void GameController::move(Character* activeChar){

    //Char doesn't register arrow keys, but int does?
    int ch;
    int enemyDirection;


    keypad(mapReader->getMapReader(), true);

    //Fixed Position to display character in window.
    wmove(mapReader->getMapReader(), 8, 25);
    waddch(mapReader->getMapReader(), 'P');

    if(activeChar == hero){
        ch = wgetch(mapReader->getMapReader());
    }
    else
    {
        enemyDirection = rand() % 4 + 1;
        switch(enemyDirection)
        {
        case 1:
            ch = KEY_RIGHT;
            break;
        case 2:
            ch = KEY_LEFT;
            break;
        case 3:
            ch = KEY_UP;
            break;
        case 4:
            ch = KEY_DOWN;
            break;
        default :
            ch = ' ';
        }
    }

    string temp = "";
    switch(ch)
    {
    case KEY_DOWN :
        makeMoves(activeChar, ch);
        break;
    case KEY_UP :
        makeMoves(activeChar, ch);
        break;
    case KEY_LEFT :
        makeMoves(activeChar, ch);
        break;
    case KEY_RIGHT :
        makeMoves(activeChar, ch);
        break;
    case '<' :
        message("TRY TO GO DOWNSTAIRS");
        break;
    case '>' :
        message("TRY TO GO UPSTAIRS");
        break;
    case 'p':
    case 'P' :
        message("PICKUP ITEM");
        break;
    case 'e' :
    case 'E' :
        //equipItem(activeChar);
        break;
    case 's' :
    case 'S' :
        message("SPECIAL ATTACK");
        break;

    }


}


void GameController::updateMap(int y, int x){
    mapReader->PrintWindow(y, x, enemy, item);
    wrefresh(mapReader->getMapReader());
}

void GameController::runGame(){
    while(isPlaying == true)
    {
        heroTurn();
        enemyTurns();

    }
}

void GameController::updateGameState(){
    updateMap(hero->getYPos(), hero->getXPos());
    statusWindow->PrintStatsWindow(hero);
    std::string temp;


    if(hero->getCurHP() < 0)
    {
        heroDead();
    }

    if(enemy.size() > 0)
    {
        for(int i = 0; i < enemy.size(); i++)
        {
            if(enemy[i]->getCurHP() < 0){
                message("Enemy cur HP check DELETE");
            }
        }
    }


    if(floorsCleared >= 10)
    {
        winGame();
    }

}

void GameController::heroDead(){
    isPlaying = false;
    message("So yeah, you kinda died, how lame...");
}

void GameController::winGame(){
    isPlaying = false;
    message("You beat the game");
}

void GameController::heroTurn(){
    move(hero);
    updateGameState();
}


void GameController::enemyTurns(){
    if(enemy.size() > 0){
    for(int i = 0; i < enemy.size(); i++)
        move(enemy[i]);
    }
}


void GameController::moveBoulder(int yPos, int xPos, int direction){
    Character* charInWay = NULL;
    charInWay = findCharacter(yPos, xPos);
    int y = yPos;
    int x = xPos;
    char upStairs = '<';
    char downStair = '>';

    switch(direction){
    case KEY_DOWN :
        y++;
        break;
    case KEY_UP :
        y--;
        break;
    case KEY_RIGHT :
        x++;
        break;
    case KEY_LEFT :
        x--;
        break;
    }

        if(mapReader->atPosition(y,x) != '@'){
            if(mapReader->atPosition(y,x) != upStairs){
                if(mapReader->atPosition(y,x) != upStairs){
                    if(charInWay == NULL){
                        mapReader->setPosition(yPos, xPos, '.');
                        mapReader->setPosition(y, x, '@');
                    }
                }

            }

        }
    }



void GameController::generateLocation(Character* tempChar){
    //logic for picking a random spot on map here
    bool legalSpot = false;
    int pickX;
    int pickY;

    Character* charAtLocation = NULL;

    while(legalSpot == false)
    {
        pickX = rand() % FLOOR_MAP_WIDTH;
        pickY = rand() % FLOOR_MAP_HEIGHT;
        //charAtLocation = hero; //findCharacter(pickY, pickX);

        if(mapReader->atPosition(pickY, pickX) != '#'){
            if(mapReader->atPosition(pickY, pickX) != '@'){
                if(mapReader->atPosition(pickY, pickX) != '<'){
                    if(mapReader->atPosition(pickY, pickX) != '>'){
                        if(charAtLocation == NULL){
                            tempChar->setYPos(pickY);
                            tempChar->setXPos(pickX);
                            legalSpot = true;
                        }
                    }
                }

            }
        }

    }
}


void GameController::makeMoves(Character* currentChar, int direction){
    int y = currentChar->getYPos();
    int x = currentChar->getXPos();
    std::string messageInput = "";

    switch(direction){
    case KEY_DOWN :
        y++;
        break;
    case KEY_UP :
        y--;
        break;
    case KEY_RIGHT :
        x++;
        break;
    case KEY_LEFT :
        x--;
        break;
    }

    //Searches for either the Hero or Enemies. If nothing is found, this will be NULL and skipped later
    Character* tempChar = NULL;
    tempChar = findCharacter(y, x);



    if(mapReader->atPosition(y,x) != '#'){
        if(mapReader->atPosition(y,x) == '@'){
            moveBoulder(y, x, direction);
        }
        else if(tempChar != NULL){
            messageInput = currentChar->getName() + " is fighting " + tempChar->getName();
            message(messageInput);
            currentChar->attack(tempChar);

        }
        else
        {
            currentChar->setYPos(y);
            currentChar->setXPos(x);
        }
    }

}

Character* GameController::findCharacter(int y, int x){
    if (x == hero->getXPos() && y == hero->getYPos()){
        return hero;
    }

    if(enemy.size() > 0){
        for(int i = 0; i < enemy.size(); i++){
        if (x == enemy[i]->getXPos() && y == enemy[i]->getYPos()){
            return enemy[i];
        }
    }

    }



    return NULL;
}


void GameController::screenTestDriver(){
    int items, enemies;
    MapReader mapReader("map0.txt",items,enemies);
    MessageWindow messageWindow;
    messageWindow.AddMessage("compatability testing");
    mapReader.PrintWindow(0,0, enemy, item);
    messageWindow.PrintMessageWindow();
}
