#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

#include "Item.h"
class Item;

class Character{
public:
    Character(); //used when making player Character
    Character(string enemy); //used only when creating enemies
    ~Character();
    virtual void specialMove();
    void generateChar();
    void levelUp();
    int attack(Character* opponent);
    void setMaxHP(int newHP);
    void setCurHP(int newHP);
    void setEXP(int newEXPAmount);
    void setStr(int newStr);
    void setDef(int newDef);
    void setSpd(int newSpd);
    void setName(string playerName);
    void setMaxSP(int newSP);
    void setCurSP(int newSP);
    void setYPos(int newY);
    void setXPos(int newX);

    int getMaxHP();
    int getCurHP();
    int getEXP();
    int getStr();
    int getDef();
    int getSpd();
    int getMaxSP();
    int getCurSP();
    int getYPos();
    int getXPos();
    string getName();
    string getEquippedItem(itemType);

    bool equipGear(Item* newGear);
    bool unequipGear(int location);
    bool pickUp(Item* newItem);
    Item* dropItem(int location);
    void useItem(Item* potion);

protected:
    int level;
    int currentHP, maxHP;
    int strength, defense, speed;
    int expPoints;
    int vision;
    string name;
    int maxSP, currentSP;
    int yPos, xPos;
    int maxPossibleHP;
    vector <Item*> heldGear;
    vector <Item*> inventory;
};


class Player: public Character
{
public:
    Player();
};


class Warrior: public Player
{
public:
    Warrior();
    void specialMove();
};

class Healer: public Player
{
public:
    Healer();
    void specialMove();//heals player
};

class Enemy: public Character
{
public:
    void generateChar();
};


class Slime: public Enemy
{
public:
    Slime();
};


inline Character::Character()
{
    level = 1;
    maxHP = rand() % 51 + 110;
    currentHP = maxHP;
    strength = rand() % 4 + 5;
    defense = rand() % 3 + 5;
    speed = rand() % 5 + 5;
    maxSP = 50;
    currentSP = maxSP;
    vision = 2;
    expPoints = 0;
    maxPossibleHP = 999;
}

inline Character::Character(string enemy) //may not need
{
    name = enemy;
    //Will the stats for enemies always be randomized?
}
/*
inline void Character::generateChar()
{
    setMaxHP(100);
    setCurHP(100);
    setStr(10);
    setDef(10);
    setSpd(10);

    setMaxSP(50);
    setCurSP(50);
    setYPos(0);
    setXPos(0);

    return;
}

inline void Character::levelUp()
{
    if (expPoints >= 100)//might not need this loop if we only call the function when we know the character will level up
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

        //After the first random stat increase, each stat has a chance of going up by one
        int statIncrease;

        for (int i = 1; i < 4; i++)
        {
            statIncrease = rand() % 1;
            if (i == 1 && statIncrease == 1)
            {
                strength = strength + 1;
            }
            else if (i == 2 && statIncrease == 1)
            {
                defense = defense + 1;
            }
            else if (i == 3 && statIncrease == 1)
            {
                speed = speed + 1;
            }
            else
            {
                break;
            }
        }

        level = level + 1;
        expPoints = expPoints - 100;

        if (maxHP > maxPossibleHP)
        {
            maxHP = maxPossibleHP;
        }

    }//end if 100 EXP loop
}

inline void Character::setMaxHP(int newHP)
{
    maxHP = newHP;
    if (maxHP > maxPossibleHP)
    {
        maxHP = maxPossibleHP;
    }
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
    if (currentHP > maxPossibleHP)
    {
        currentHP = maxPossibleHP;
    }
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

inline void Character::setCurSP(int newSP)
{
    currentSP = newSP;
}

inline int Character::getCurSP()
{
    return currentSP;
}

inline void Character::setMaxSP(int newSP)
{
    maxSP = newSP;
}

inline int Character::getMaxSP()
{
    return maxSP;
}

inline void Character::setYPos(int newY)
{
    yPos = newY;
}

inline int Character::getYPos()
{
    return yPos;
}

inline void Character::setXPos(int newX)
{
    xPos = newX;
}

inline int Character::getXPos()
{
    return xPos;
}

inline void Character::equipGear(Item piece)
{
    maxHP = maxHP + piece.getHPBuff();
    maxSP = maxSP + piece.getSPBuff();
    strength = strength + piece.getStrBuff();
    defense = defense + piece.getDefBuff();
    speed = speed + piece.getSpdBuff();

    if (maxHP > 999)
    {
        maxHP = 999;
    }
}

inline void Character::unequipGear(Item piece)
{
    maxHP = maxHP - piece.getHPBuff();
    maxSP = maxSP - piece.getSPBuff();
    strength = strength - piece.getStrBuff();
    defense = defense - piece.getDefBuff();
    speed = speed - piece.getSpdBuff();
}



inline Warrior::Warrior()
{
    strength = strength + 5;
    defense = defense + 5;
}

inline Healer::Healer()
{
    strength = strength - 3;
    defense = defense - 2;
    maxHP = maxHP - 20;
    currentHP = maxHP;
    //will add more stat adjustments as we add more stats
}

inline void Enemy::generateChar()
{
    setMaxHP(50);
    setCurHP(maxHP);
    setStr(10);
    setDef(10);
    setSpd(10);

    return;
}

inline Slime::Slime()
{
    name = "Slime";
    strength = strength - 3;
    defense = defense - 3;
    speed = speed - 1;

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

    if (currentSP > 10)
    {
        currentHP = currentHP + 60;

        if (currentHP > maxHP)
        {
            currentHP = maxHP;
        }

        currentSP = currentSP - 10;

        if (currentSP < 0)
        {
            currentSP = 0;
        }
    }
}
*/

#endif //CHARACTER_H
