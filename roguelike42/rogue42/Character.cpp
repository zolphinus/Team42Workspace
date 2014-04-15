#include "Character.h"

 void Character::generateChar()
{

    setMaxHP(100);
    setCurHP(100);
    setStr(10);
    setDef(10);
    setSpd(10);
    setMaxSP(50);
    setCurSP(50);
    setYPos(0);
    setXPos(0);

    return;
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

        //After the first random stat increase, each stat has a chance of going up by one
        int statIncrease;

        for (int i = 1; i < 4; i++)
        {
            statIncrease = rand() % 1;
            if (i == 1 && statIncrease == 1)
            {
                strength = strength + 1;
            }
            else if (i == 2 && statIncrease == 1)
            {
                defense = defense + 1;
            }
            else if (i == 3 && statIncrease == 1)
            {
                speed = speed + 1;
            }
            else
            {
                break;
            }
        }

        level = level + 1;
        expPoints = expPoints - 100;

        if (maxHP > maxPossibleHP)
        {
            maxHP = maxPossibleHP;
        }

    }//end if 100 EXP loop
}

void Character::attack(Character* opponent)
{
    int damage;

    if (speed > opponent->getSpd())//do damage to opponent before they do any to you
    {
        if (currentHP > 0)
        {
            int oppHP = opponent->getCurHP();
            int myStr = strength;
            damage = myStr - opponent->getDef();
            oppHP = oppHP - damage;
            opponent->setCurHP(oppHP);
        }
        if (opponent->getCurHP() > 0)
        {
            int myHP = currentHP;
            int oppStr = opponent->getStr();
            damage = oppStr - defense;
            myHP = myHP - damage;
            currentHP = myHP;
        }
    }

    else//opponent does damage first
    {
        if (opponent->getCurHP() > 0)
        {
            int myHP = currentHP;
            int oppStr = opponent->getStr();
            damage = oppStr - defense;
            myHP = myHP - damage;
            currentHP = myHP;
        }

        if (currentHP > 0)
        {
            int oppHP = opponent->getCurHP();
            int myStr = strength;
            damage = myStr - opponent->getDef();
            oppHP = oppHP - damage;
            opponent->setCurHP(oppHP);
        }
    }
}

 void Character::setMaxHP(int newHP)
{
    maxHP = newHP;
    if (maxHP > maxPossibleHP)
    {
        maxHP = maxPossibleHP;
    }
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
    if (currentHP > maxPossibleHP)
    {
        currentHP = maxPossibleHP;
    }
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

 void Character::setCurSP(int newSP)
{
    currentSP = newSP;
}

 int Character::getCurSP()
{
    return currentSP;
}

 void Character::setMaxSP(int newSP)
{
    maxSP = newSP;
}

 int Character::getMaxSP()
{
    return maxSP;
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

 void Character::equipGear(Item newGear) //need to redo
{
    //first check if the item in inventory is gear
    if (newGear.getType() != 'D' && newGear.getType() != 'P')
    {
        //if you have no held gear, push the piece into gear vector
        if (heldGear.size() == 0)
        {
            heldGear.push_back(newGear);
        }

        /*
        if you have gear equipped, check to see if you already
        have that type of gear equipped.  If you do, you can't equip the new piece
        */
        else
        {
            //True when you already have the type of equipment on
            bool alreadyEquipped = false;

            for (int i= 0; i < heldGear.size()-1; i++)
            {
                if (newGear.getType() == heldGear[i].getType())
                {
                    alreadyEquipped = true;
                }
            }

            if (alreadyEquipped == false)
            {
                heldGear.push_back(newGear);
            }

        }

    }

    /*maxHP = maxHP + piece.getHPBuff();
    maxSP = maxSP + piece.getSPBuff();
    strength = strength + piece.getStrBuff();
    defense = defense + piece.getDefBuff();
    speed = speed + piece.getSpdBuff();*/

    if (maxHP > 999)
    {
        maxHP = 999;
    }
}

/*
 void Character::unequipGear(Item piece)
{
    maxHP = maxHP - piece.getHPBuff();
    maxSP = maxSP - piece.getSPBuff();
    strength = strength - piece.getStrBuff();
    defense = defense - piece.getDefBuff();
    speed = speed - piece.getSpdBuff();
}


 void Character::statIncrease(Item piece)
{
    maxHP = maxHP + piece.getHPBuff();
    maxSP = maxSP + piece.getSPBuff();
    strength = strength + piece.getStrBuff();
    defense = defense + piece.getDefBuff();
    speed = speed + piece.getSpdBuff();
}
*/

 void Character::pickUp(Item newItem)
{
    if (inventory.size() < 6)//check if inventory is full
    {
        inventory.push_back(newItem);//if not, add item to inventory
    }
}

/*
 void Character::useItem(Item potion)
{
    if (potion.getType() == 'P')//only works if the item is a healing item
    {
        currentHP = currentHP + potion.getHPHeal();
        currentSP = currentSP + potion.getSPHeal();

        if(currentHP > maxHP)
        {
            currentHP = maxHP;
        }

        if(currentSP > maxSP)
        {
            currentSP = maxSP;
        }
    }
}
*/
Player::Player()
{
}

 Warrior::Warrior()
{
    strength = strength + 5;
    defense = defense + 5;
}

 Healer::Healer()
{
    strength = strength - 3;
    defense = defense - 2;
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

 void Warrior::specialMove()
{
//will add more to special move when we know what the special moves should do
}

 void Healer::specialMove()
{

    if (currentSP > 10)
    {
        currentHP = currentHP + 60;

        if (currentHP > maxHP)
        {
            currentHP = maxHP;
        }

        currentSP = currentSP - 10;

        if (currentSP < 0)
        {
            currentSP = 0;
        }
    }
}
