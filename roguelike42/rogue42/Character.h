#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;


class Character{
public:
    Character(); //used when making player Character
    Character(string enemy); //used only when creating enemies
    virtual void specialMove();
    void generateChar();
    void setMaxHP(int newHP);
    int getMaxHP();
    void setEXP(int newEXPAmount);
    int getEXP();
    void setCurHP(int newHP);
    int getCurHP();
    void setStr(int newStr);
    int getStr();
    void setDef(int newDef);
    int getDef();
    void setSpd(int newSpd);
    int getSpd();
    void setName(string playerName);
    void levelUp();
    string getName();
    void setYPos(int newY);
    int getYPos();
    void setXPos(int newX);
    int getXPos();

protected:
    int level;
    int currentHP;
    int maxHP;
    int strength;
    int defense;
    int speed; //who attacks first
    int expPoints;
    int vision;
    string name;
    int yPos;
    int xPos;
};

class Player: public Character
{

};

class warrior: public Player
{
public:
    warrior();
    void specialMove();
};

class healer: public Player
{
public:
    healer();
    void specialMove();
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

Character::Character()
{
    srand(time(NULL));
    level = 1;
    maxHP = rand() % 51 + 100;
    currentHP = maxHP;
    strength = rand() % 5 + 5;
    defense = rand() % 5 + 5;
    speed = rand() % 1 + 2;
    vision = 2;
    expPoints = 0;
}

Character::Character(string enemy)
{
    name = enemy;
    //Will the stats for enemies always be randomized?
}

void Character::generateChar()
{
    string userName;
    cout << "Please enter your name: ";
    cin >> userName;

    setName(userName);
    setMaxHP(100);
    setCurHP(100);
    setStr(10);
    setSpd(10);

    return;
}

void Character::setMaxHP(int newHP)
{
    maxHP = newHP;
}

int Character::getMaxHP()
{
    return maxHP;
}

void Character::setEXP(int newEXPAmount)
{
    expPoints = newEXPAmount;
}

int Character::getEXP()
{
    return expPoints;
}

void Character::setCurHP(int newHP)
{
    currentHP = newHP;
}

int Character::getCurHP()
{
    return currentHP;
}

void Character::setStr(int newStr)
{
    strength = newStr;
}

int Character::getStr()
{
    return strength;
}

void Character::setDef(int newDef)
{
    defense = newDef;
}

int Character::getDef()
{
    return defense;
}

void Character::setSpd(int newSpd)
{
    speed = newSpd;
}

int Character::getSpd()
{
    return speed;
}

void Character::setName(string playerName)
{
    name = playerName;
}

string Character::getName()
{
    return name;
}

void Character::setYPos(int newY)
{
    yPos = newY;
}

int Character::getYPos()
{
    return yPos;
}

void Character::setXPos(int newX)
{
    xPos = newX;
}

int Character::getXPos()
{
    return xPos;
}

void Character::levelUp()
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
        else
        {
            cout << "Error occurred!" << endl;
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
            if (i == 2 && statIncrease == 1)
            {
                defense = defense + 1;
            }
            if (i == 3 && statIncrease == 1)
            {
                speed = speed + 1;
            }
        }

        level = level + 1;
        expPoints = expPoints - 100;

    }//end if 100 EXP loop
}

warrior::warrior()
{
    strength = strength + 5;
    defense = defense + 5;
}

healer::healer()
{
    strength = strength - 3;
    maxHP = maxHP - 20;
    currentHP = maxHP;
    //will add more stat adjustments as we add more stats
}

void Enemy::generateChar()
{
    setMaxHP(50);
    setCurHP(maxHP);
    setStr(10);
    setDef(10);
    setSpd(10);

    return;
}

Slime::Slime()
{
    name = "Slime";
    strength = strength - 3;
    defense = defense - 3;
    speed = speed - 1;

}


//PLACEHOLDER FUNCTIONS
void Character::specialMove()
{
//will add more to special move when we know what the special moves should do
}

void warrior::specialMove()
{
//will add more to special move when we know what the special moves should do
}

void healer::specialMove()
{
//will add more to special move when we know what the special moves should do
}

#endif
