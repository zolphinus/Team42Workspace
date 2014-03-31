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
    characterTestDriver();
    gameControllerDriver();

    return 0;
}


void characterTestDriver(){
    //Testing the classes
    character hero = generateChar();

    cout << "Character name is " <<hero.getName() << endl;
    cout << "Current HP is " << hero.getCurHP() << endl;
    cout << "Max HP is " << hero.getMaxHP() << endl;
    cout << "Strength is " << hero.getStr() << endl;
}


void gameControllerDriver(){


}
