#include "Character.h"

void Character::generateChar()
{
    string userName;
    cout << "Please enter your name: ";
    cin >> userName;
    if (userName.length() > 10)
    {
        userName.resize(10);
    }

    setName(userName);
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
    if (expPoints >= 100)
    {
        int hpIncrease = rand() % 15 + 5;

        maxHP = maxHP + hpIncrease;

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
            int strIncrease = rand() % 1;
            int defIncrease = rand() % 1;
            int spdIncrease = rand() % 1;

            strength = strength + strIncrease;
            defense = defense + defIncrease;
            speed = speed + spdIncrease;

            /*if (i == 1 && statIncrease == 1)
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
            }*/
        }

        level = level + 1;
        expPoints = expPoints - 100;

        if (maxHP > maxPossibleHP)
        {
            maxHP = maxPossibleHP;
        }

    }//end if 100 EXP loop
}

void Character::attack(Character& opponent)
{
    int damage; //used to calculate damage

    //Stats after applying equipment enhancements
    int currentStr = strength;
    int currentDef = defense;
    int currentSpd = speed;

    //Applying equipment enhancements to stats if holding gear
    if (heldGear.size() != 0)
    {
        for (int i = 0; i < heldGear.size()-1; i++)
        {
            currentStr = currentStr + heldGear[i].getStrBuff();
            currentDef = currentDef + heldGear[i].getStrBuff();
            currentSpd = currentSpd + heldGear[i].getSpdBuff();
        }
    }

    //if you are faster than an enemy, you attack first
    if (currentSpd > opponent.getSpd())
    {
        if (currentHP > 0)
        {
            int oppHP = opponent.getCurHP();
            int myStr = currentStr;
            damage = myStr - opponent.getDef();
            if (damage < 0)
            {
                damage = 0;
            }
            oppHP = oppHP - damage;
            opponent.setCurHP(oppHP);
        }

        if (opponent.getCurHP() > 0)
        {
            int myHP = currentHP;
            int oppStr = opponent.getStr();
            damage = oppStr - defense;
            if (damage < 0)
            {
                damage = 0;
            }
            myHP = myHP - damage;
            currentHP = myHP;
        }
    }

    //if the enemy is faster than you, it attacks first
    else
    {
        if (opponent.getCurHP() > 0)
        {
            int myHP = currentHP;
            int oppStr = opponent.getStr();
            damage = oppStr - defense;
            if (damage < 0)
            {
                damage = 0;
            }
            myHP = myHP - damage;
            currentHP = myHP;
        }

        if (currentHP > 0)
        {
            int oppHP = opponent.getCurHP();
            int myStr = currentStr;
            damage = myStr - opponent.getDef();
            if (damage < 0)
            {
                damage = 0;
            }
            oppHP = oppHP - damage;
            opponent.setCurHP(oppHP);
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

inline void Character::setXPos(int newX)
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
        //If you have no held gear, push the piece into gear vector
        if (heldGear.size() == 0)
        {
            heldGear.push_back(newGear);
        }

        /*
        If you have gear equipped, check to see if you already
        have on the type of gear you're trying to equip.
        If you do, you can't equip the new piece,
        because you can only equip one of each type of gear
        */
        else
        {
            //True when you already have the type of equipment on
            bool alreadyEquipped = false;

            for (int i = 0; i < heldGear.size()-1; i++)
            {
                if (newGear.getType() == heldGear[i].getType())
                {
                    alreadyEquipped = true;
                }
            }

            //If you don't have that kind of gear already equipped, put on the new piece!
            if (alreadyEquipped == false)
            {
                heldGear.push_back(newGear);
                maxHP = maxHP + newGear.getHPBuff();
                maxSP = maxSP + newGear.getSPBuff();
            }
        }
    }

    if (maxHP > maxPossibleHP)
    {
        maxHP = maxPossibleHP;
    }
}

void Character::unequipGear(Item piece)
{



    maxHP = maxHP - piece.getHPBuff();
    maxSP = maxSP - piece.getSPBuff();
    strength = strength - piece.getStrBuff();
    defense = defense - piece.getDefBuff();
    speed = speed - piece.getSpdBuff();
}

void Character::pickUp(Item newItem)
{
    if (inventory.size() < 6)//check if inventory is full
    {
        inventory.push_back(newItem);//if not, add item to inventory
    }
}

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

Character::~Character()
{
}

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
    maxHP = 10;
    currentHP = maxHP;
    strength = strength - 3;
    defense = defense - 3;
    speed = speed - 1;

}


//PLACEHOLDER FUNCTIONS
void Character::specialMove()
{
}

void Warrior::specialMove()//might just make this a stronger attack
{
//will add more to special move when we know what the special moves should do
}

void Healer::specialMove()
{

    if (currentSP >= 10)
    {
        currentHP = currentHP + 80;

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
