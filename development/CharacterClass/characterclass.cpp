#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

#include "characterclass.h"

using namespace std;

character generateChar();
character generateRanChar();

int main()
{
    //Testing the classes
    character player = generateChar();
    character* hero = &player;

    cout << hero -> getName() << endl;
    cout << hero -> getCurHP() << endl;
    cout << hero -> getStr() << endl;
    warrior dude;
    cout << dude.getStr() << " STR" << endl;

    return 0;
}

character generateChar()
{
    character player;
    string playerName;

    cout << "What is your name?" << endl;
    cin >> playerName;
    player.setName(playerName);

    player.setMaxHP(10);
    player.setCurHP(10);
    player.setStr(10);
    player.setSpd(10);

    return player;
}

character generateRanChar()
{
    character player;

    return player;
}

