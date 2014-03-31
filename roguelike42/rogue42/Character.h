#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;


class character{
public:
    character(); //used when making player character
    character(string enemy); //used only when creating enemies
    virtual void specialMove();
    void setMaxHP(int newHP);
    int getMaxHP();
    void setCurHP(int newHP);
    int getCurHP();
    void setStr(int newStr);
    int getStr();
    void setSpd(int newSpd);
    int getSpd();
    void setName(string playerName);
    string getName();
protected:
    int currentHP;
    int maxHP = rand() % 100 + 120;
    int strength = rand() % 5 + 5;
    int speed;
    string name;
};


class warrior: public character
{
public:
    warrior();
    virtual void specialMove();
};

class healer: public character
{
public:
    healer();
    virtual void specialMove();
};

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

character::character()
{
    currentHP = maxHP;
}

character::character(string enemy)
{
    name = enemy;
    //Will the stats for enemies always be randomized?
}

void character::setMaxHP(int newHP)
{
    maxHP = newHP;
}

int character::getMaxHP()
{
    return maxHP;
}

void character::setCurHP(int newHP)
{
    currentHP = newHP;
}

int character::getCurHP()
{
    return currentHP;
}

void character::setStr(int newStr)
{
    strength = newStr;
}

int character::getStr()
{
    return strength;
}

void character::setSpd(int newSpd)
{
    speed = newSpd;
}

int character::getSpd()
{
    return speed;
}

void character::setName(string playerName)
{
    name = playerName;
}

string character::getName()
{
    return name;
}

warrior::warrior()
{
    strength = strength + 5;
    //will add more stat adjustments as we add more stats
}

healer::healer()
{
    strength = strength - 3;
    maxHP = maxHP - 20;
    currentHP = maxHP;
    //will add more stat adjustments as we add more stats
}

void character::specialMove()
{
//will add more to special move when we know what the special moves should do
}

void warrior::specialMove()
{
//will add more to special move when we know what the special moves should do
}

void healer::specialMove()
{
//will add more to special move when we know what the special moves should do
}

#endif
