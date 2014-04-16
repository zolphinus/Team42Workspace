#include <iostream>
#include "Character.h"

#include "GameController.h"
#include "MapReader.h"
#include "MessageWindow.h"
#include "StatsWindow.h"

using std::cout;
using std::cin;
using std::endl;



void characterTestDriver();
void gameControllerDriver();
void screenTestDriver();
void statusTestDriver();

int main()
{
    //srand(time(NULL)); // random seed for randomization of stats, when it matters
    //characterTestDriver();
    gameControllerDriver();
    //screenTestDriver();


    return 0;
}

void screenTestDriver()
{
    GameController test;
    test.screenTestDriver();

}

void characterTestDriver(){
    //Testing the classes
    srand(time(NULL));

    Character hero;
    hero.generateChar();
    cout << "Character name is " <<hero.getName() << endl;
    cout << "Current HP is " << hero.getCurHP() << endl;
    cout << "Max HP is " << hero.getMaxHP() << endl;
    cout << "Strength is " << hero.getStr() << endl;
    cout << "Defense is " << hero.getDef() << endl;
    cout << "Speed is " << hero.getSpd() << endl;

    cout << endl;

    hero.setEXP(100);
    hero.levelUp();

    cout << endl;

    cout << "You leveled up! Here are your new stats" << endl;
    cout << "Current HP is " << hero.getCurHP() << endl;
    cout << "Max HP is " << hero.getMaxHP() << endl;
    cout << "Strength is " << hero.getStr() << endl;
    cout << "Defense is " << hero.getDef() << endl;
    cout << "Speed is " << hero.getSpd() << endl << endl;

    Item* testItem = new Item(W);
    testItem -> setName("Grass Sword");
    testItem -> setStrBuff(100);
    testItem -> setType(W);
    hero.equipGear(testItem);
    cout << "New strength after equipping " << testItem -> getName()
        << " is " << hero.getStr() + testItem ->getStrBuff() << endl << endl;

    Slime *evilSlime = new Slime;
    cout << "An evil Slime appeared! It has " << evilSlime -> getCurHP() << " HP!" << endl;
    hero.attack(evilSlime);
    cout << "After attacking it, it only has " << evilSlime -> getCurHP() << " HP!" << endl;

}


void gameControllerDriver(){
    char temp;
    GameController ourGame;

    ourGame.message("TESTING MESSAGE WINDOW");
    ourGame.message("TESTING SCROLL");
    ourGame.message("HELLO WORLD 2.0!");
    ourGame.message("LET'S BEGIN!");
    ourGame.message("[DISPLAY STORY STUFFS HERE]");

    ourGame.runGame();


}

/*
void GameController::screenTestDriver(){
    MapReader mapReader("map0.txt");
    MessageWindow messageWindow;
    messageWindow.AddMessage("compatability testing");
    mapReader.PrintWindow(0,0, enemy);
    messageWindow.PrintMessageWindow();
}
*/
void statusTestDriver()
{
    Character *Hero=new Character;
    Hero->generateChar();
    StatsWindow statusWindow;
    statusWindow.PrintStatsWindow(Hero);
}
