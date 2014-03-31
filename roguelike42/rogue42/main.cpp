#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "Character.h"

int main()
{
    cout << "Hello world!" << endl;

    //Testing the classes
    character hero = generateChar();

    cout << "Character name is " <<hero.getName() << endl;
    cout << "Current HP is " << hero.getCurHP() << endl;
    cout << "Max HP is " << hero.getMaxHP() << endl;
    cout << "Strength is " << hero.getStr() << endl;

    return 0;
}
