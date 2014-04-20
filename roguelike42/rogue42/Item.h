#ifndef ITEM_H
#define ITEM_H


#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include "GameConfig.h"

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
    Item(itemType newType);
    void generateItem();
    void setName(string name);
    string getName();
    void setType(itemType typeOfItem);
    itemType getType();
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
    itemType type;
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

#endif //ITEM_H
