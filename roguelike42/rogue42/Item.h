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

/*
inline Item::Item()
{
    type = 'D';
}


inline void Item::setName(string name)
{
    itemName = name;
}

inline string Item::getName()
{
    return itemName;
}


inline void Item::setType(char gearType)
{
    type = gearType;
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
inline int Item::getHPBuff()
{
    return hpBonus;
}


inline int Item::getSPBuff()
{
    return spBonus;
}


inline int Item::getStrBuff()
{
    return strBonus;
}

inline int Item::getDefBuff()
{
    return defBonus;
}


inline int Item::getSpdBuff()
{
    return spdBonus;
}


inline void Item::setHPBuff(int newValue)
{
    hpBonus = newValue;
}


inline void Item::setSPBuff(int newValue)
{
    spBonus = newValue;
}


inline void Item::setStrBuff(int newValue)
{
    strBonus = newValue;
}


inline void Item::setDefBuff(int newValue)
{
    defBonus = newValue;
}


inline void Item::setSpdBuff(int newValue)
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

*/

#endif
