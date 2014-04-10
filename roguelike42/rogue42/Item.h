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
    void setName(string name);
protected:
    string itemName;
};

class HealItem: public Item
{
public:
    HealItem();
    void useItem()
protected:
    int HPAmount;
    int SPAmount;
};

class Gear: public Item
{
public:
    Gear();
    void equipGear(Character& holder)
    void unequipGear(Character& holder)
protected:
    int hpBonus;
    int spBonus;
    int strBonus;
    int defBonus;
    int spdBonus;
};

class Weapon: public Gear

Gear::Gear()
{
    hpBonus = 0;
    spBonus = 0;
    strBonus = 0;
    defBonus = 0;
    spdBonus = 0;
}

void Item::setName(string name)
{
        itemName = name;
}

//don't know if I should make this a character function or an item function
void Gear::equipGear(Character& holder)
{
    int newHP = holder.getMaxHP() + hpBonus;
    holder.setMaxHP(newHP);
    int newSP = holder.getMaxSP() + spBonus;
    holder.setMaxSP(newSP);
    int newStr = holder.getStr() + strBonus;
    holder.setStr(newStr);
    int newDef = holder.getDef() + defBonus;
    holder.setDef(newDef);
    int newSpd = holder.getSPd() + spdBonus;
    holder.setSpd(newSpd);
}

void Gear::unequipGear(Character& holder)
{
    int newHP = holder.getMaxHP() - hpBonus;
    holder.setMaxHP(newHP);
    int newSP = holder.getMaxSP() - spBonus;
    holder.setMaxSP(newSP);
    int newStr = holder.getStr() - strBonus;
    holder.setStr(newStr);
    int newDef = holder.getDef() - defBonus;
    holder.setDef(newDef);
    int newSpd = holder.getSPd() - spdBonus;
    holder.setSpd(newSpd);
}


#endif
