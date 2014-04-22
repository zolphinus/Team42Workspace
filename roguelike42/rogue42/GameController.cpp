#include "GameController.h"
#include <string>
#include "Character.h"
#include "MapFiles.h"
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

#define SCREEN_SIZE 40


GameController::GameController()
{
    initGame();
    if(isTesting == TRUE)
    {
        enemyNum = 150;
        itemNum = 100;
        enemy.resize(enemyNum);
        item.resize(itemNum);
        makeEnemies();
        makeItems();
        genLocations();
    }
}

GameController::~GameController()
{
    cleanUpGame();
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
    if (userName.length() > 10)
    {
        userName.resize(10);
    }
    hero->setName(userName);
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
            clearConsole();
            cout << "PLEASE SELECT A JOB!!!" << endl;
        }
    }
}

Character* GameController::getHero(){
    return hero;
}

void GameController::makeEnemies(){

    if(enemy.size() > 0){
        for( int i = 0; i < enemy.size(); i++)
        {
            randomEnemy(enemy[i]);
        }

    }
}

void GameController::makeItems(){

    if(item.size() > 0){
        for( int i = 0; i < item.size(); i++)
        {
            randomItem(item[i]);
        }

    }
}


void GameController::randomEnemy(Enemy*& newEnemy){
    //INCREASE THIS MOD VALUE AS YOU ADD ENEMY TYPES TO FUNCTION
    int temp = rand() % 13;

    //BE SURE TO USE INT VALUES AND NOT CHAR

    if(temp >=0 && temp <= 6)
    {
        newEnemy = new Slime();
    }

    if(temp >=7 && temp <= 10)
    {
        newEnemy = new Wolf();
    }

    if(temp >=11 && temp <= 12)
    {
        newEnemy = new Orc();
    }

    if(temp == 13)
    {
        newEnemy = new Giant();
    }



}

void GameController::randomItem(Item*& newItem){
    itemType temp = itemType(rand() % P +1);

        newItem = new Item(temp);

}


void GameController::cleanUpGame(){

    delete hero;
    if(enemy.size() > 0){
        for( int i = 0; i < enemy.size(); i++)
        {
            delete enemy[i];
        }
    }

    if(item.size() > 0){
        for( int i = 0; i < item.size(); i++)
        {
            delete item[i];
        }
    }

    item.resize(0);
    enemy.resize(0);

    delete messageWindow;
    messageWindow = NULL;
    delete mapReader;
    mapReader = NULL;
    delete statusWindow;
    statusWindow = NULL;
    endwin();
}




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
        goDownstairs(activeChar->getYPos(), activeChar->getXPos());
        break;
    case '>' :
        if(mapReader->atPosition(activeChar->getYPos(), activeChar->getXPos()) == '>')
        {
            message("A mysterious force prevents you from going upstairs!");
        }
        else
        {
            message("There are no stairs!");
        }

        break;
    case 'p':
    case 'P' :
        pickUpItem(activeChar);

        break;
    case 'e' :
    case 'E' :
        equipItem(activeChar);
        break;
    case 'u' :
    case 'U' :
        unequipItem(activeChar);
        break;
    case 's' :
    case 'S' :
        message("SPECIAL ATTACK NOT IMPLEMENTED YET");
        break;
    case 'd' :
    case 'D' :
        dropItem(activeChar);
        break;
    case 'i' :
    case 'I' :
        useItem(activeChar);
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

void GameController::updateGameState(Character* currentChar){
    updateMap(hero->getYPos(), hero->getXPos());
    statusWindow->PrintStatsWindow(hero);
    std::string temp;

    if(switchesOnFloor == 0){
        message("The Sokoban Puzzle was completed!");
        temp = currentChar->getName() + " received 50 EXP!!!";
        message(temp);
        currentChar->setEXP(currentChar->getEXP() + 50);
        switchesOnFloor = -1;
    }


    if(hero->getCurHP() < 0)
    {
        heroDead();
    }

    if(enemy.size() > 0)
    {
        for(int i = 0; i < enemy.size(); i++)
        {
            if(enemy[i]->getEXP() > 100)
            {
                message(enemy[i]->getName() + " grows stronger!");
                enemy[i]->levelUp();
            }
            if(enemy[i]->getCurHP() <= 0){
                delete enemy[i];
                enemy.erase(enemy.begin()+i);
                i--;
            }
        }
    }

    if(hero->getEXP() > 100)
    {
        message(hero->getName() + " has leveled up!");
        hero->levelUp();
    }

    int floorsToWin = rand() % 5 + 4;
    if(floorsCleared >= floorsToWin)
    {
        winGame();
    }

}

void GameController::heroDead(){
    isPlaying = false;
    message("So yeah, you kinda died, how lame...");

    //Use WGETCH as a display stop
    wgetch(messageWindow->getMessageWindow());
}

void GameController::winGame(){
    isPlaying = false;
    message("");
    message("");
    message("");
    message("Congratulations! You somehow managed to escape Princess Adrienne's dungeon!");
    message("");
    message("");
    message("But the evil princess is nowhere to be found...");
    message("");
    //Use WGETCH as a display stop
    wgetch(messageWindow->getMessageWindow());
}

void GameController::heroTurn(){
    move(hero);
    updateGameState(hero);
}


void GameController::enemyTurns(){
    if(enemy.size() > 0){
    for(int j = 0; j < enemy.size(); j++){
        move(enemy[j]);
        updateGameState(enemy[j]);
    }
    }
}


void GameController::moveBoulder(int yPos, int xPos, int direction){
    Character* charInWay = NULL;
    Item* itemOnGround = NULL;
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
    charInWay = findCharacter(y, x);
    itemOnGround = findItem(y, x);


    if(mapReader->atPosition(y,x) != '#'){
        if(mapReader->atPosition(y,x) != '@'){
            if(mapReader->atPosition(y,x) != upStairs){
                if(mapReader->atPosition(y,x) != upStairs){
                    if(charInWay == NULL){
                        if(mapReader->atPosition(y,x) == '%'){
                            mapReader->setPosition(yPos, xPos, '.');
                            mapReader->setPosition(y, x, '&');
                            message("*click*");
                            message("It appears a switch has been hit!");
                            switchesOnFloor--;
                        }
                        else{
                            if(itemOnGround != NULL)
                            {
                                message(itemOnGround->getName() + " was crushed under the weight of the boulder!");
                                removeItem(itemOnGround);
                            }
                            mapReader->setPosition(yPos, xPos, '.');
                            mapReader->setPosition(y, x, '@');
                        }
                    }
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
        charAtLocation = NULL;
        charAtLocation = findCharacter(pickY, pickX);

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

void GameController::generateLocation(Item* tempItem){
    //logic for picking a random spot on map here
    bool legalSpot = false;
    int pickX;
    int pickY;

    Item* itemAtLocation = NULL;


    while(legalSpot == false)
    {
        pickX = rand() % FLOOR_MAP_WIDTH;
        pickY = rand() % FLOOR_MAP_HEIGHT;
        itemAtLocation = NULL;
        //itemAtLocation = findItem(pickY, pickX);

        if(mapReader->atPosition(pickY, pickX) != '#'){
            if(mapReader->atPosition(pickY, pickX) != '@'){
                if(mapReader->atPosition(pickY, pickX) != '<'){
                    if(mapReader->atPosition(pickY, pickX) != '>'){
                        if(itemAtLocation == NULL){
                            tempItem->setYPos(pickY);
                            tempItem->setXPos(pickX);
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
            messageInput = currentChar->getName() + " attacks " + tempChar->getName() + "!";
            message(messageInput);
            currentChar->attack(tempChar);

            if(tempChar->getCurHP() <= 0)
            {
                messageInput = currentChar->getName() + " has killed " + tempChar->getName() + "!";
                currentChar->setEXP(currentChar->getEXP() + tempChar->getEXP());
                message(messageInput);
            }

            if(currentChar->getCurHP() <= 0)
            {
                messageInput = tempChar->getName() + " has killed " + currentChar->getName() + "!";
                tempChar->setEXP(currentChar->getEXP() + tempChar->getEXP());
                message(messageInput);
            }

        }
        else{
            if(mapReader->atPosition(y,x) != '&');
            {
                currentChar->setYPos(y);
                currentChar->setXPos(x);
            }
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


Item* GameController::findItem(int y, int x){
    if(item.size() > 0){
        for(int i = 0; i < item.size(); i++){
        if (x == item[i]->getXPos() && y == item[i]->getYPos()){
            return item[i];
        }
        }
    }
    return NULL;
}


void GameController::genLocations(){

    //Populates the map with random locations
    generateLocation(hero);
    if(enemy.size() > 0){
        for(int i = 0; i < enemy.size(); i++){
            generateLocation(enemy[i]);
        }
    }

    if(item.size() > 0){
        for(int i = 0; i < item.size(); i++){
            generateLocation(item[i]);
        }
    }
}


void GameController::initGame(){
    srand(time(NULL));

    enemyNum = rand() % 10 + 8;
    itemNum = rand() % 10 + 3;
    makeHero();
    switchesOnFloor = -1;
    storyline();
    isTesting = false;

    startCurseStuff();
    messageWindow = new MessageWindow();
    mapReader = new MapReader("map0.txt");

    enemy.resize(enemyNum);
    item.resize(itemNum);
    makeEnemies();
    makeItems();
    genLocations();
    //Prepares the message window for display
    message("You wake up in a daze.");

    statusWindow = new StatsWindow();
    statusWindow->PrintStatsWindow(hero);
    isPlaying = true;
    floorsCleared = 0;

    wmove(mapReader->getMapReader(), hero->getYPos(), hero->getXPos());
    mapReader->PrintWindow(hero->getYPos(), hero->getXPos(), enemy, item);
}

void GameController::goDownstairs(int y, int x){

    if(mapReader->atPosition(y, x) == '<')
    {
        //Double random generation for a more even variance
    int doubleRandom = rand() % 3;
    this->itemNum = rand() % 3 + 3 + doubleRandom;
    doubleRandom = rand () % 10;
    this->enemyNum = rand() % 6 + 5 + doubleRandom;

    //cleanup Vectors
    itemEnemyReset();
    //load new map



    mapReader->ReadMap(randomMap());

    //Decides if a map has a Sokoban Puzzle
    doubleRandom = rand() % 4;
    if(doubleRandom == 2){
        generateBoulderAndSwitch();
    }

    //generate enemies and items
    enemy.resize(enemyNum);
    item.resize(itemNum);
    makeEnemies();
    makeItems();

    //generate positions on new map
    genLocations();
    floorsCleared++;

    wmove(mapReader->getMapReader(), hero->getYPos(), hero->getXPos());
    mapReader->PrintWindow(hero->getYPos(), hero->getXPos(), enemy, item);
    }



}


void GameController::itemEnemyReset()
{
    //Resets the vectors for the next floor
    if(enemy.size() > 0){
        for( int i = 0; i < enemy.size(); i++)
        {
            delete enemy[i];
        }
    }

    if(item.size() > 0){
        for( int i = 0; i < item.size(); i++)
        {
            delete item[i];
        }
    }
}


void GameController::screenTestDriver(){
    int items, enemies;
    MapReader mapReader("map0.txt");
    MessageWindow messageWindow;
    messageWindow.AddMessage("compatability testing");
    mapReader.PrintWindow(0,0, enemy, item);
    messageWindow.PrintMessageWindow();
}


void GameController::storyline(){
    string buffer;

    clearConsole();

    cout << hero->getName() + "," << endl;

    cout << "You've arrived at the castle of Princess Adrienne in response to a frantic" << endl;
    cout << "message for help. You burst through the doors, sword drawn and ready to fight " << endl;
    cout << "for your princess, only to see her sitting calmly on her throne. She smiles, " << endl;
    cout << "and you suddenly feel dizzy. You close your eyes to gather yourself..." << endl;
    cout << "When you open them you're not standing in a grand hall, but a small," << endl;
    cout << "dark stone room." << endl << endl << endl;

    cout << "You hear a voice and realize it's Princess Adrienne..." << endl << endl << endl;

    cout << "PRESS ENTER TO CONTINUE";
    consoleWait();

    clearConsole();

    cout << "THE FALL OF CHIVALRY" << endl << endl << endl;
    cout << "CONTROLS" << endl;
    cout << "P - Pick Up Item" << endl;
    cout << "D - Drop Item" << endl;
    cout << "E - Equip Item" << endl;
    cout << "U - Unequip Item" << endl;
    cout << "I - Use Item" << endl;
    cout << "< - Go Downstairs" << endl;
    cout << "> - Go Upstairs" << endl;
    cout << "S - Special Actions (not yet implemented)" << endl << endl;

    cout << "ICONS" << endl;
    cout << "P - Player" << endl;
    cout << "E - Enemy"  << endl;
    cout << "I - Item" << endl;
    cout << "@ - Boulder" << endl;
    cout << "% - Boulder Hole" << endl;
    cout << "& - Boulder in Hole"  << endl;
    cout << "< - Downstairs" << endl;
    cout << "> - Upstairs" << endl << endl;

    cout << "PRESS ENTER TO CONTINUE";
    consoleWait();

    clearConsole();

    cout << "OBJECTIVE" << endl;

    cout << "The goal of the game is to progress down through the floors of Adrienne's Castle" << endl;
    cout << "Will you survive the Fall of Chivalry?" << endl << endl << endl << endl;

    //Formatting the lazy way
    cout << "PRESS ENTER TO CONTINUE" << endl << endl << endl << endl << endl << endl;
    consoleWait();

}

void GameController::consoleWait(){
    //Waits for user to press enter
    cin.sync();
    cin.get();
}


void GameController::clearConsole(){
    cout << string(SCREEN_SIZE, '\n');
}


void GameController::pickUpItem(Character* activeChar){
    Item* tempItem = NULL;
    bool pickedUp = false;

    tempItem = findItem(activeChar->getYPos(), activeChar->getXPos());
    pickedUp = activeChar->pickUp(tempItem);

    if(pickedUp == true)
    {
        message("Picked up " + tempItem->getName());
        removeItem(tempItem);
    }
    else
    {
        message("You cannot do that!");
    }

    tempItem = NULL;
}


void GameController::removeItem(Item* tempItem){
    //scroll through items and find one to delete
    if(item.size() > 0){
        for( int i = 0; i < item.size(); i++)
        {
            if(tempItem == item[i]){
                item.erase(item.begin() + i);
            }
        }
    }
}

void GameController::equipItem(Character* tempChar){
    int ch;
    int itemsToDisplay = 0;
    int inventoryIndex = -1;
    bool didEquip = false;
    Item* tempItem = NULL;
    string itemDisplay;
    keypad(messageWindow->getMessageWindow(), true);

    message("Equip an item? (Y/N)");
    ch = wgetch(messageWindow->getMessageWindow());

    switch(ch){
    case 'Y' :
    case 'y':
        for(int i = 0; i < tempChar->getMaxInventorySize(); i++){
            tempItem = tempChar->getInventory(i);
            if(tempItem != NULL){
                itemDisplay = NumberToString(i) + ") " + tempItem->getName();
                message(itemDisplay);
                itemsToDisplay++;
            }
        }

        if(itemsToDisplay == 0){
            message("You have no items to equip!");
        }
        else{
            ch = wgetch(messageWindow->getMessageWindow());

        //ch needs to convert to 0 through 5
        switch(ch){
        case '0':
            inventoryIndex = 0;
            break;
        case '1':
            inventoryIndex = 1;
            break;
        case '2':
            inventoryIndex = 2;
            break;
        case '3':
            inventoryIndex = 3;
            break;
        case '4':
            inventoryIndex = 4;
            break;
        case '5':
            inventoryIndex = 5;
            break;
        default:
            inventoryIndex = -1;
        }

            tempItem = tempChar->getInventory(inventoryIndex);
            didEquip = tempChar->equipGear(tempItem);

            if(didEquip == true){
                itemDisplay = "You equipped " + tempItem->getName() + "!";
                message(itemDisplay);
            }
            else{
                message("You cannot do that!");
            }


            break;
        }

    }
}

void GameController::dropItem(Character* tempChar){
    int ch;
    int itemsToDisplay = 0;
    int inventoryIndex = -1;
    bool didDrop = false;
    Item* tempItem = NULL;
    string itemDisplay;
    keypad(messageWindow->getMessageWindow(), true);

    message("Drop an item? (Y/N)");
    ch = wgetch(messageWindow->getMessageWindow());

    switch(ch){
    case 'Y' :
    case 'y':
        for(int i = 0; i < tempChar->getMaxInventorySize(); i++){
            tempItem = tempChar->getInventory(i);
            if(tempItem != NULL){
                itemDisplay = NumberToString(i) + ") " + tempItem->getName();
                message(itemDisplay);
                itemsToDisplay++;
            }
        }

        if(itemsToDisplay == 0){
            message("You have no items to drop!");
        }
        else{
            ch = wgetch(messageWindow->getMessageWindow());

        switch(ch){
        case '0':
            inventoryIndex = 0;
            break;
        case '1':
            inventoryIndex = 1;
            break;
        case '2':
            inventoryIndex = 2;
            break;
        case '3':
            inventoryIndex = 3;
            break;
        case '4':
            inventoryIndex = 4;
            break;
        case '5':
            inventoryIndex = 5;
            break;
        default:
            inventoryIndex = -1;
        }

            tempItem = tempChar->dropItem(inventoryIndex);


            if(tempItem != false){
                itemDisplay = "You dropped " + tempItem->getName() + " on the ground.";
                tempItem->setYPos(tempChar->getYPos());
                tempItem->setXPos(tempChar->getXPos());
                item.push_back(tempItem);
                message(itemDisplay);
            }
            else{
                message("You cannot do that!");
            }
            break;
        }

    }
}

void GameController::useItem(Character* tempChar){
    int ch;
    int itemsToDisplay = 0;
    int inventoryIndex = -1;
    bool didUse = false;
    Item* tempItem = NULL;
    string itemDisplay;
    keypad(messageWindow->getMessageWindow(), true);

    message("Use an item? (Y/N)");
    ch = wgetch(messageWindow->getMessageWindow());

    switch(ch){
    case 'Y' :
    case 'y':
        for(int i = 0; i < tempChar->getMaxInventorySize(); i++){
            tempItem = tempChar->getInventory(i);
            if(tempItem != NULL){
                itemDisplay = NumberToString(i) + ") " + tempItem->getName();
                message(itemDisplay);
                itemsToDisplay++;
            }
        }

        if(itemsToDisplay == 0){
            message("You have no items to use!");
        }
        else{
            ch = wgetch(messageWindow->getMessageWindow());

        switch(ch){
        case '0':
            inventoryIndex = 0;
            break;
        case '1':
            inventoryIndex = 1;
            break;
        case '2':
            inventoryIndex = 2;
            break;
        case '3':
            inventoryIndex = 3;
            break;
        case '4':
            inventoryIndex = 4;
            break;
        case '5':
            inventoryIndex = 5;
            break;
        default:
            inventoryIndex = -1;
        }

            tempItem = tempChar->getInventory(inventoryIndex);
            didUse = tempChar->useItem(inventoryIndex);

            if(didUse == true){
                itemDisplay = "You used " + tempItem->getName() + ".";
                message(itemDisplay);

                if(tempItem->getHPHeal() > 0){
                    itemDisplay = tempChar->getName() + " healed " + NumberToString(tempItem->getHPHeal()) + " HP!";
                    message(itemDisplay);
                }
                if(tempItem->getSPHeal() > 0){
                    itemDisplay = tempChar->getName() + " restored " + NumberToString(tempItem->getSPHeal()) + " SP!";
                    message(itemDisplay);
                }

            }
            else{
                message("You cannot do that!");
            }
            break;
        }

    }
}



void GameController::unequipItem(Character* tempChar){
    int ch;
    int itemsToDisplay = 0;
    int inventoryIndex = -1;
    bool didUnequip = false;
    Item* tempItem = NULL;
    string itemDisplay;
    keypad(messageWindow->getMessageWindow(), true);

    message("Unequip an item? (Y/N)");
    ch = wgetch(messageWindow->getMessageWindow());

    switch(ch){
    case 'Y' :
    case 'y':
        for(int i = 0; i < tempChar->getEquipSize(); i++){
            tempItem = tempChar->getEquipment(i);
            if(tempItem != NULL){
                itemDisplay = NumberToString(i) + ") " + tempItem->getName();
                message(itemDisplay);
                itemsToDisplay++;
            }
        }

        if(itemsToDisplay == 0){
            message("You have no items to equip!");
        }
        else{
            ch = wgetch(messageWindow->getMessageWindow());

        //ch needs to convert to 0 through 5
        switch(ch){
        case '0':
            inventoryIndex = 0;
            break;
        case '1':
            inventoryIndex = 1;
            break;
        case '2':
            inventoryIndex = 2;
            break;
        case '3':
            inventoryIndex = 3;
            break;
        case '4':
            inventoryIndex = 4;
            break;
        case '5':
            inventoryIndex = 5;
            break;
        default:
            inventoryIndex = -1;
        }

            tempItem = tempChar->getEquipment(inventoryIndex);
            didUnequip = tempChar->unequipGear(inventoryIndex);

            if(didUnequip == true){
                itemDisplay = "You unequipped " + tempItem->getName() + "!";
                message(itemDisplay);
            }
            else{
                message("You cannot do that!");
            }


            break;
        }

    }
}



void GameController::generateBoulderAndSwitch(){
    int pickX;
    int pickY;
    bool legalSpot = false;
    switchesOnFloor = rand() % 4 + 3;

    for(int i = 0; i < switchesOnFloor; i++){
        while(legalSpot == false){
            pickX = rand() % FLOOR_MAP_WIDTH;
            pickY = rand() % FLOOR_MAP_HEIGHT;
            if(mapReader->atPosition(pickY, pickX) != '#'){
                if(mapReader->atPosition(pickY, pickX) != '@'){
                    if(mapReader->atPosition(pickY, pickX) != '<'){
                        if(mapReader->atPosition(pickY, pickX) != '>'){
                            if(mapReader->atPosition(pickY, pickX) != '%'){
                                mapReader->setPosition(pickY, pickX, '@');
                                legalSpot = true;
                            }
                        }
                    }
                }
            }
        }
    }

    legalSpot = false;

    for(int j = 0; j < switchesOnFloor; j++){
        while(legalSpot == false){
            pickX = rand() % FLOOR_MAP_WIDTH;
            pickY = rand() % FLOOR_MAP_HEIGHT;
            if(mapReader->atPosition(pickY, pickX) != '#'){
                if(mapReader->atPosition(pickY, pickX) != '@'){
                    if(mapReader->atPosition(pickY, pickX) != '<'){
                        if(mapReader->atPosition(pickY, pickX) != '>'){
                            if(mapReader->atPosition(pickY, pickX) != '%'){
                                mapReader->setPosition(pickY, pickX, '%');
                                legalSpot = true;
                            }
                        }
                    }
                }
            }
        }
    }
}

void GameController::testMode(bool testing){
    isTesting = testing;
}
