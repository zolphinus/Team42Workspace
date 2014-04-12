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
protected:
    string itemName;
};

class HealItem: public Item
{
public:
    HealItem(string name);
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

class Weapon: public Gear
{
};

inline Gear::Gear(string name)
{
    itemName = name;
    hpBonus = 0;
    spBonus = 0;
    strBonus = 0;
    defBonus = 0;
    spdBonus = 0;
}

inline void Item::setName(string name)
{
    itemName = name;
}

inline string Item::getName()
{
    return itemName;
}

inline int Gear::getHPBuff()
{
    return hpBonus;
}

inline int Gear::getSPBuff()
{
    return spBonus;
}

inline int Gear::getStrBuff()
{
    return strBonus;
}

inline int Gear::getDefBuff()
{
    return defBonus;
}

inline int Gear::getSpdBuff()
{
    return spdBonus;
}

inline void Gear::setHPBuff(int newValue)
{
    hpBonus = newValue;
}

inline void Gear::setSPBuff(int newValue)
{
    spBonus = newValue;
}

inline void Gear::setStrBuff(int newValue)
{
    strBonus = newValue;
}

inline void Gear::setDefBuff(int newValue)
{
    defBonus = newValue;
}

inline void Gear::setSpdBuff(int newValue)
{
    spdBonus = newValue;
}


#endif
