#include <iostream>
#include "Character.h"
#include "GameController.h"

using std::cout;
using std::cin;
using std::endl;



void characterTestDriver();
void gameControllerDriver();

int main()
{
    srand(time(NULL)); // random seed for randomization of stats, when it matters
    characterTestDriver();
    //gameControllerDriver();

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
    GameController ourGame;
    cout << ourGame.hero->getStr() << endl;
}
