#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>

#define MAX_INVENTORY_SIZE 6

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
    void setJobTitle(string);
    int getEquipSize();

    int getLevel();
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
    string getJobTitle();
    string getEquippedItem(itemType);
    Item* getInventory(int);
    Item* getEquipment(int);

    int getMaxInventorySize();

    bool equipGear(Item* newGear);
    bool unequipGear(int location);
    bool pickUp(Item* newItem);
    Item* dropItem(int location);
    bool useItem(int location);
    void removeInventory(Item*);

protected:
    string jobName;
    int level;
    int currentHP, maxHP;
    int strength, defense, speed;
    int expPoints;
    int vision;
    int maxInventorySize;
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
    maxInventorySize = MAX_INVENTORY_SIZE;
}

inline Character::Character(string enemy)
{
    name = enemy;
}

#endif //CHARACTER_H
