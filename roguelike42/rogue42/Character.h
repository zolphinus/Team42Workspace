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
    int speed; //who attacks first
    int expPoints;
    int vision;
    string name;
};

class Warrior: public Character
{
public:
    Warrior();
    void specialMove();
};

class Healer: public Character
{
public:
    Healer();
    void specialMove();
};

inline Character::Character()
{

    level = 1;
    maxHP = rand() % 100 + 120;
    currentHP = maxHP;
    strength = rand() % 5 + 5;
    defense = rand() % 5 + 5;
    speed = rand() % 1+ 2;
    vision = 2;
    expPoints = 0;
}

inline Character::Character(string enemy)
{
    name = enemy;
    //Will the stats for enemies always be randomized?
}

inline void Character::generateChar()
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

inline void Character::setMaxHP(int newHP)
{
    maxHP = newHP;
}

inline int Character::getMaxHP()
{
    return maxHP;
}

inline void Character::setEXP(int newEXPAmount)
{
    expPoints = newEXPAmount;
}

inline int Character::getEXP()
{
    return expPoints;
}

inline void Character::setCurHP(int newHP)
{
    currentHP = newHP;
}

inline int Character::getCurHP()
{
    return currentHP;
}

inline void Character::setStr(int newStr)
{
    strength = newStr;
}

inline int Character::getStr()
{
    return strength;
}

inline void Character::setDef(int newDef)
{
    defense = newDef;
}

inline int Character::getDef()
{
    return defense;
}

inline void Character::setSpd(int newSpd)
{
    speed = newSpd;
}

inline int Character::getSpd()
{
    return speed;
}

inline void Character::setName(string playerName)
{
    name = playerName;
}

inline string Character::getName()
{
    return name;
}

inline void Character::levelUp()
{
    if (expPoints >= 0)//might not need this loop if we only call the function when we know the character will level up
    {
        maxHP = maxHP + rand() % 5 + 10;

        int statUp = rand() % 3 + 1;//decides what stat goes up randomly

        //Randomly raise a stat by one point
        if (statUp == 1) //may change to switch statement later
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
        }
        else
        {
            cout << "Error occurred!" << endl;
        }

        //After the first random stat increase, each stat has a chance of going up by one
        int statIncrease;

        for (int i = 1; i < 4; i++)
        {
            statIncrease = rand() % 1;
            if (i == 1 && statIncrease == 1)
            {
                strength = strength + 1;
            }
            if (i == 2 && statIncrease == 1)
            {
                defense = defense + 1;
            }
            if (i == 3 && statIncrease == 1)
            {
                speed = speed + 1;
            }
        }

        level = level + 1;
        expPoints = expPoints - 100;

    }//end if 100 EXP loop
}

inline Warrior::Warrior()
{
    strength = strength + 5;
    //will add more stat adjustments as we add more stats
}

inline Healer::Healer()
{
    strength = strength - 3;
    maxHP = maxHP - 20;
    currentHP = maxHP;
    //will add more stat adjustments as we add more stats
}


//PLACEHOLDER FUNCTIONS
inline void Character::specialMove()
{
//will add more to special move when we know what the special moves should do
}

inline void Warrior::specialMove()
{
//will add more to special move when we know what the special moves should do
}

inline void Healer::specialMove()
{
//will add more to special move when we know what the special moves should do
}

#endif
