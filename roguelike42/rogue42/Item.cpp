#include "Item.h"

//Item Functions
Item::Item(itemType newType)
{
    type = newType;//D = default type
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

void Item::generateItem()
{
    itemName = "Test"; //will add random names later

    //if item does not have a type, assign it one.
    if (type == D)
    {
        type = itemType(rand() % P);
    }

    //assign random stats based on item type
    switch(type)
    {
    case H:
        defBonus = rand() % 80 + 20;
        break;
    case W:
        strBonus = rand() % 100 + 20;
        break;
    case R:
        defBonus = rand() % 100 + 20;
        break;
    case A:
        strBonus = rand() % 50 + 10;
        defBonus = rand() % 50 + 10;
        spdBonus = rand() % 50 + 10;
        break;
    case P:
        hpHealAmount = rand() % 50 + 10;
        spHealAmount = rand() % 30 + 10;
        break;
    default:
        break;
    }
}

void Item::setName(string name)
{
    itemName = name;
}


string Item::getName()
{
    return itemName;
}


void Item::setType(itemType typeOfItem)
{
    type = typeOfItem;
}


itemType Item::getType()
{
    return type;
}


void Item::setYPos(int newY)
{
    yPos = newY;
}


int Item::getYPos()
{
    return yPos;
}


void Item::setXPos(int newX)
{
    xPos = newX;
}


int Item::getXPos()
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

int Item::getHPHeal()
{
    return hpHealAmount;
}

int Item::getSPHeal()
{
    return spHealAmount;
}
