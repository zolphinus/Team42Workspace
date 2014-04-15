#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
Items have a char to represent what type of item they are:
H = helm
R = armor
W = weapon
A = accessory
P = potion
D = default
*/

class Item
{
public:
    Item();
    void setName(string name);
    string getName();
    void setType(char itemType);
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
inline Item::Item()
{
    type = 'D';//D = default type
    yPos = 0;
    xPos = 0;
    hpBonus = 0;
    spBonus = 0;
    strBonus = 0;
    defBonus = 0;
    spdBonus = 0;
    hpHealAmount = 0;
    spHealAmount = 0;
}

inline void Item::setName(string name)
{
    itemName = name;
}

inline string Item::getName()
{
    return itemName;
}

inline void Item::setType(char itemType)
{
    type = itemType;
}

inline char Item::getType()
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
inline void Item::setHPHeal(int pointsToHeal)
{
    hpHealAmount = pointsToHeal;
}

inline void Item::setSPHeal(int pointsToHeal)
{
    spHealAmount = pointsToHeal;
}

inline int Item::getHPHeal()
{
    return hpHealAmount;
}

inline int Item::getSPHeal()
{
    return spHealAmount;
}

#endif //ITEM_H
