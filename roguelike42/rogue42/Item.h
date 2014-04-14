#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

#include "Character.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


class Item
{
public:
    Item();
    void setName(string name);
    string getName();
    void setType(char gearType);
    char getType();
    void setYPos(int newY);
    int getYPos();
    void setXPos(int newX);

    int getXPos();
    int getHPBuff();
    int getSPBuff();
    int getStrBuff();
    int getDefBuff();
    int getSpdBuff();
    void setHPBuff(int newValue);
    void setSPBuff(int newValue);
    void setStrBuff(int newValue);
    void setDefBuff(int newValue);
    void setSpdBuff(int newValue);

    void setHPHeal(int pointsToHeal);
    void setSPHeal(int pointsToHeal);
    int getHPHeal();
    int getSPHeal();

protected:
    string itemName;
    char type;
    int yPos, xPos;
    //Stat bonuses from equipment
    int hpBonus;
    int spBonus;
    int strBonus;
    int defBonus;
    int spdBonus;
    //How much potions should heal
    int hpHealAmount;
    int spHealAmount;
};


//Item Functions
Item::Item()
{
    type = 'D';
}

void Item::setName(string name)
{
    itemName = name;
}

string Item::getName()
{
    return itemName;
}

void Item::setType(char gearType)
{
    type = gearType;
}

char Item::getType()
{
    return type;
}

inline void Item::setYPos(int newY)
{
    yPos = newY;
}

inline int Item::getYPos()
{
    return yPos;
}

inline void Item::setXPos(int newX)
{
    xPos = newX;
}

inline int Item::getXPos()
{
    return xPos;
}

//Gear Functions
int Item::getHPBuff()
{
    return hpBonus;
}

int Item::getSPBuff()
{
    return spBonus;
}

int Item::getStrBuff()
{
    return strBonus;
}

int Item::getDefBuff()
{
    return defBonus;
}

int Item::getSpdBuff()
{
    return spdBonus;
}

void Item::setHPBuff(int newValue)
{
    hpBonus = newValue;
}

void Item::setSPBuff(int newValue)
{
    spBonus = newValue;
}

void Item::setStrBuff(int newValue)
{
    strBonus = newValue;
}

void Item::setDefBuff(int newValue)
{
    defBonus = newValue;
}

void Item::setSpdBuff(int newValue)
{
    spdBonus = newValue;
}

//Healing Item functions
void Item::setHPHeal(int pointsToHeal)
{
    hpHealAmount = pointsToHeal;
}

void Item::setSPHeal(int pointsToHeal)
{
    spHealAmount = pointsToHeal;
}

#endif
