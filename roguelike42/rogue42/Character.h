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


class Character{
public:
    Character(); //used when making player Character
    Character(string enemy); //used only when creating enemies
    virtual void specialMove();
    void generateChar();
    void levelUp();
    void attack(Character& opponent);
    void setMaxHP(int newHP);
    int getMaxHP();
    void setCurHP(int newHP);
    int getCurHP();
    void setEXP(int newEXPAmount);
    int getEXP();
    void setStr(int newStr);
    int getStr();
    void setDef(int newDef);
    int getDef();
    void setSpd(int newSpd);
    int getSpd();
    void setName(string playerName);
    string getName();
    void setMaxSP(int newSP);
    int getMaxSP();
    void setCurSP(int newSP);
    int getCurSP();
    void setYPos(int newY);
    int getYPos();
    void setXPos(int newX);
    int getXPos();
    void equipGear(int inventoryLoc);
    void unequipGear(Gear piece);
    void addInventory(Item newItem);
    void useItem();
    void statIncrease(Gear piece);

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
    vector <Item> heldGear;
    vector <Item> inventory;
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
    maxHP = rand() % 51 + 100;
    currentHP = maxHP;
    strength = rand() % 5 + 5;
    defense = rand() % 5 + 5;
    speed = rand() % 5 + 5;
    maxSP = 50;
    currentSP = maxSP;
    vision = 2;
    expPoints = 0;
    maxPossibleHP = 999;
}

inline Character::Character(string enemy)
{
    name = enemy;
    //Will the stats for enemies always be randomized?
}

#endif
