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


void characterTestDriver(){
    //Testing the classes
    Character hero;
    hero.generateChar();
    cout << "Character name is " <<hero.getName() << endl;
    cout << "Current HP is " << hero.getCurHP() << endl;
    cout << "Max HP is " << hero.getMaxHP() << endl;
    cout << "Strength is " << hero.getStr() << endl;
    cout << "Defense is " << hero.getDef() << endl;
    cout << "Speed is " << hero.getSpd() << endl;
}


void gameControllerDriver(){
    int temp;
    GameController ourGame;
    ourGame.message("BOOOOOOOOOOOOOOO");
    ourGame.message("asdf");
    ourGame.message("mediocraty");
    cin >> temp;


}


void screenTestDriver(){
    MapReader mapReader("map0.txt");
    MessageWindow messageWindow;
    messageWindow.AddMessage("compatability testing");
    mapReader.PrintWindow(0,0);
    messageWindow.PrintMessageWindow();
}

void statusTestDriver()
{
    Character *Hero=new Character;
    Hero->generateChar();
    StatsWindow statusWindow;
    statusWindow.PrintStatsWindow(Hero);
}
