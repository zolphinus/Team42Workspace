#include "Item.h"

//Item Functions
Item::Item()
{
    type = D;//D = default type
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


Item::Item(itemType newType)
{
    type = newType;
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
    //if item does not have a type, assign it one.
    if (type == D)
    {
        type = itemType(rand() % P);
    }

    int itemMaterial = rand() % 4;//What the item is made of
    int itemClass = rand() % 4;//What kind of weapon/armor is it?
    int accType = rand() % 8;
    int tempBonus = 0;//bonus to add to stats based on item type

    //Determine the material the item is made of (or color for potions)
    if (type != A)
    {
        switch(itemMaterial){
        case 0:
            if (type != P)
            {
                itemName = "Wooden";
            }
            else
            {
                itemName = "Green Potion";
                hpHealAmount = 20;
            }
            break;
        case 1:
            if (type != P)
            {
                itemName = "Rusted";
                tempBonus = -1;
            }
            else
            {
                itemName = "Blue Potion";
                hpHealAmount = 10;
                spHealAmount = 10;
            }
            break;
        case 2:
            if (type != P)
            {
                itemName = "Iron";
                tempBonus = 2;
            }
            else
            {
                itemName = "Red Potion";
                hpHealAmount = 25;
                spHealAmount = 15;
            }
            break;
        case 3:
            if (type != P)
            {
                itemName = "Mithril";
                tempBonus = 5;
            }
            else
            {
                itemName = "Purple Potion";
                hpHealAmount = 40;
                spHealAmount = 20;
            }
            break;
        case 4:
            if (type != P)
            {
                itemName = "Grass";
                tempBonus = 15;
            }
            else
            {
                itemName = "Gold Potion";
                hpHealAmount = 10;
                spHealAmount = 10;
            }
            break;
        default:
            break;
        }
    }
    else//determine what accessory it will be
    {
        switch (accType)
        {
        case 0:
            itemName = "Feather Boots";
            spdBonus = 5 + (rand() % 5);
            break;
        case 1:
            itemName = "Holy Ring";
            hpBonus = 50;
            defBonus = rand() % 5 + 1;
            break;
        case 2:
            itemName = "Attack Charm";
            strBonus = rand() % 5 + 1;
            break;
        case 3:
            itemName = "Attack Ring";
            strBonus = rand() % 10 + 5;
            break;
        case 4:
            itemName = "Plain Ring";
            break;
        case 5:
            itemName = "Cursed Ring";
            strBonus = -2;
            defBonus = -2;
            spdBonus = -2;
            break;
        case 6:
            itemName = "Magic Ring";
            spBonus = rand() % 20 + 20;
            break;
        case 7:
            itemName = "Life Charm";
            hpBonus = rand() % 40 + 40;
            break;
        case 8:
            itemName = "Attack Ring";
            strBonus = rand() % 10 + 5;
            break;
        default:
            break;
        }
    }

    //accessories and potions are finished at this point
    if (type == P || type == A)
    {
        return;
    }

    //determines what kind of weapon/armor/helm
    switch (itemClass)
    {
    case 0:
        if (type == W)
        {
            itemName.append(" Knife");
            strBonus = tempBonus;
        }
        else if (type == R)
        {
            itemName.append(" Plate");
            defBonus = tempBonus;
        }
        else
        {
            itemName.append(" Helm");
            defBonus = tempBonus;
        }
        break;
    case 1:
        if (type == W)
        {
            itemName.append(" Rod");
            defBonus = tempBonus + rand() % 3;
            hpBonus = 20 + tempBonus;
        }
        else if (type == R)
        {
            itemName.append(" Mail");
            defBonus = tempBonus + rand() % 3 + 5;
        }
        else
        {
            itemName.append(" Helm");
            defBonus = tempBonus + rand() % 2;
        }
        break;
    case 2:
        if (type == W)
        {
            itemName.append(" Axe");
            strBonus = tempBonus + rand() % 15 + 5;
        }
        else if (type == R)
        {
            itemName.append(" Armor");
            defBonus = tempBonus + rand() % 7 + 4;
        }
        else
        {
            itemName.append(" Helm");
            defBonus = tempBonus + rand() % 5 + 1;
        }
        break;
    case 3:
        if (type == W)
        {
            itemName.append(" Sword");
            strBonus = tempBonus + 10 + rand() % 2;
        }
        else if (type == R)
        {
            itemName.append(" Armor");
            defBonus = tempBonus + rand() % 7 + 4;
        }
        else
        {
            itemName.append(" Helm");
            defBonus = tempBonus + rand() % 5 + 1;
        }
        break;
    case 4:
        if (type == W)
        {
            itemName = "Beam Sword";
            strBonus = rand() % 25 + 23;
        }
        else if (type == R)
        {
            itemName = "Battlesuit";
            defBonus = rand() % 20 + 18;
        }
        else
        {
            itemName.append(" Helm");
            defBonus = tempBonus + rand() % 8 + 2;
        }
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
