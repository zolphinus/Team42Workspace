#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;


class Character{
public:
    Character(); //used when making player Character
    Character(string enemy); //used only when creating enemies
    virtual void specialMove();
    void generateChar();
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
    int maxHP;
    int strength;
    int speed;
    string name;
};


class warrior: public Character
{
public:
    warrior();
    virtual void specialMove();
};

class healer: public Character
{
public:
    healer();
    virtual void specialMove();
};

Character::Character()
{
    maxHP = rand() % 100 + 120;
    currentHP = maxHP;
    strength = rand() % 5 + 5;
    speed = rand() % 1 + 2;
    this -> speed = 90;
}

Character::Character(string enemy)
{
    name = enemy;
    //Will the stats for enemies always be randomized?
}

void Character::generateChar()
{
    string userName;
    cout << "Please Enter your name: ";
    cin >> userName;

    setName(userName);
    setMaxHP(100);
    setCurHP(100);
    setStr(10);
    setSpd(10);

    return;
}

void Character::setMaxHP(int newHP)
{
    maxHP = newHP;
}

int Character::getMaxHP()
{
    return maxHP;
}

void Character::setCurHP(int newHP)
{
    currentHP = newHP;
}

int Character::getCurHP()
{
    return currentHP;
}

void Character::setStr(int newStr)
{
    strength = newStr;
}

int Character::getStr()
{
    return strength;
}

void Character::setSpd(int newSpd)
{
    speed = newSpd;
}

int Character::getSpd()
{
    return speed;
}

void Character::setName(string playerName)
{
    name = playerName;
}

string Character::getName()
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


//PLACEHOLDER FUNCTIONS
void Character::specialMove()
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
