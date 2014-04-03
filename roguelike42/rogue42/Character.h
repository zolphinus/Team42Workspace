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
    void setEXP(int newEXPAmount);
    int getEXP();
    void setCurHP(int newHP);
    int getCurHP();
    void setStr(int newStr);
    int getStr();
    void setDef(int newDef);
    int getDef();
    void setSpd(int newSpd);
    int getSpd();
    void setName(string playerName);
    void levelUp();
    string getName();
protected:
    int level;
    int currentHP;
    int maxHP;
    int strength;
    int defense;
    int speed;
    int expPoints;
    int vision;
    string name;
};

class warrior: public Character
{
public:
    warrior();
    void specialMove();
};

class healer: public Character
{
public:
    healer();
    void specialMove();
};

Character::Character()
{
    level = 1;
    maxHP = rand() % 100 + 120;
    currentHP = maxHP;
    strength = rand() % 5 + 5;
    defense = rand() % 5 + 5;
    speed = rand() % 1 + 2;
    vision = 2;
    expPoints = 0;
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

void Character::setEXP(int newEXPAmount)
{
    expPoints = newEXPAmount;
}

int Character::getEXP()
{
    return expPoints;
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

void Character::setDef(int newDef)
{
    defense = newDef;
}

int Character::getDef()
{
    return defense;
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

void Character::levelUp() //Not finished
{
    if (expPoints >= 100)//might not need this loop if we only call the function when we know the character will level up
    {
        maxHP = maxHP + rand() % 5 + 10;

        int statUp = rand() % 3 + 1;

        if (statUp == 1)
        {
            strength = strength + 1;
        }
        else if (statUp == 2)
        {
            defense = defense + 1;
        }
        else if (statUp == 3)
        {
            speed = speed + 1;
            //Should speed even go up?
        }
        else
        {
            cout << "Error occured!" << endl;
        }
    }
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
