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

protected:
    string itemName;
    char type;
};

class HealItem: public Item
{
public:
    HealItem(string name);
    void setHPAmount(int pointsToHeal);
    int getHPAmount();
    void setSPAmount(int pointsToHeal);
    int getSPAmount();
protected:
    int HPAmount;
    int SPAmount;
};

class Gear: public Item
{
public:
    Gear(string name);
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

protected:
    int hpBonus;
    int spBonus;
    int strBonus;
    int defBonus;
    int spdBonus;
};

HealItem::HealItem(string name)
{
    name = itemName;
    HPAmount = 0;
    SPAmount = 0;
}

Gear::Gear(string name)
{
    itemName = name;
    hpBonus = 0;
    spBonus = 0;
    strBonus = 0;
    defBonus = 0;
    spdBonus = 0;
}

//Item Functions
Item::Item()
{
    type = 'N';
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

//Gear Functions
int Gear::getHPBuff()
{
    return hpBonus;
}

int Gear::getSPBuff()
{
    return spBonus;
}

int Gear::getStrBuff()
{
    return strBonus;
}

int Gear::getDefBuff()
{
    return defBonus;
}

int Gear::getSpdBuff()
{
    return spdBonus;
}

void Gear::setHPBuff(int newValue)
{
    hpBonus = newValue;
}

void Gear::setSPBuff(int newValue)
{
    spBonus = newValue;
}

void Gear::setStrBuff(int newValue)
{
    strBonus = newValue;
}

void Gear::setDefBuff(int newValue)
{
    defBonus = newValue;
}

void Gear::setSpdBuff(int newValue)
{
    spdBonus = newValue;
}

//Healing Item functions
void HealItem::setHPAmount(int pointsToHeal)
{
    HPAmount = pointsToHeal;
}

void HealItem::setSPAmount(int pointsToHeal)
{
    SPAmount = pointsToHeal;
}

#endif
