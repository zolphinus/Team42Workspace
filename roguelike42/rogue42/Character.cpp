#include "Character.h"

inline void Character::generateChar()
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

inline void Character::levelUp()
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

void Character::attack(Character& opponent)
{
    int damage;

    if (speed > opponent.getSpd())//do damage to opponent before they do any to you
    {
        if (currentHP > 0)
        {
            int oppHP = opponent.getCurHP();
            int myStr = strength;
            damage = myStr - opponent.getDef();
            oppHP = oppHP - damage;
            opponent.setCurHP(oppHP);
        }

        if (opponent.getCurHP() > 0)
        {
            int myHP = currentHP;
            int oppStr = opponent.getStr();
            damage = oppStr - defense;
            myHP = myHP - damage;
            currentHP = myHP;
        }
    }

    else//opponent does damage first
    {
        if (opponent.getCurHP() > 0)
        {
            int myHP = currentHP;
            int oppStr = opponent.getStr();
            damage = oppStr - defense;
            myHP = myHP - damage;
            currentHP = myHP;
        }

        if (currentHP > 0)
        {
            int oppHP = opponent.getCurHP();
            int myStr = strength;
            damage = myStr - opponent.getDef();
            oppHP = oppHP - damage;
            opponent.setCurHP(oppHP);
        }
    }
}

inline void Character::setMaxHP(int newHP)
{
    maxHP = newHP;
    if (maxHP > maxPossibleHP)
    {
        maxHP = maxPossibleHP;
    }
}

inline int Character::getMaxHP()
{
    return maxHP;
}

inline void Character::setEXP(int newEXPAmount)
{
    expPoints = newEXPAmount;
}

inline int Character::getEXP()
{
    return expPoints;
}

inline void Character::setCurHP(int newHP)
{
    currentHP = newHP;
    if (currentHP > maxPossibleHP)
    {
        currentHP = maxPossibleHP;
    }
}

inline int Character::getCurHP()
{
    return currentHP;
}

inline void Character::setStr(int newStr)
{
    strength = newStr;
}

inline int Character::getStr()
{
    return strength;
}

inline void Character::setDef(int newDef)
{
    defense = newDef;
}

inline int Character::getDef()
{
    return defense;
}

inline void Character::setSpd(int newSpd)
{
    speed = newSpd;
}

inline int Character::getSpd()
{
    return speed;
}

inline void Character::setName(string playerName)
{
    name = playerName;
}

inline string Character::getName()
{
    return name;
}

inline void Character::setCurSP(int newSP)
{
    currentSP = newSP;
}

inline int Character::getCurSP()
{
    return currentSP;
}

inline void Character::setMaxSP(int newSP)
{
    maxSP = newSP;
}

inline int Character::getMaxSP()
{
    return maxSP;
}

inline void Character::setYPos(int newY)
{
    yPos = newY;
}

inline int Character::getYPos()
{
    return yPos;
}

inline void Character::setXPos(int newX)
{
    xPos = newX;
}

inline int Character::getXPos()
{
    return xPos;
}

inline void Character::equipGear(int inventoryLoc) //need to redo
{
    //first check if the item in inventory is gear
    if (inventory[inventoryLoc].getType() == 'H' || inventory[inventoryLoc].getType() == 'R'
        || inventory[inventoryLoc].getType() == 'W' || inventory[inventoryLoc].getType() == 'A')
    {
        //if you have no held gear, push the piece into gear vector
        if (heldGear.size() == 0)
        {
            heldGear.push_back(inventory[inventoryLoc]);
            statIncrease(inventory[inventoryLoc]);
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

inline void Character::unequipGear(Gear piece)
{
    maxHP = maxHP - piece.getHPBuff();
    maxSP = maxSP - piece.getSPBuff();
    strength = strength - piece.getStrBuff();
    defense = defense - piece.getDefBuff();
    speed = speed - piece.getSpdBuff();
}

inline void Character::statIncrease(Gear piece)
{
    maxHP = maxHP + piece.getHPBuff();
    maxSP = maxSP + piece.getSPBuff();
    strength = strength + piece.getStrBuff();
    defense = defense + piece.getDefBuff();
    speed = speed + piece.getSpdBuff();
}

inline void Character::addInventory(Item newItem)
{
    if (inventory.size() < 6)//check if inventory is full
    {
        inventory.push_back(newItem);//if not, add item to inventory
    }
}

inline void Character::useItem()
{

}

Player::Player()
{
    //makes placeholder item for later use
    /*Gear emptyItem("Empty");
    emptyItem.setType('E');
    for (int i = 0; i < heldGear.size(); i++)
    {
        heldGear[i] = emptyItem;
    }
    */
}

inline Warrior::Warrior()
{
    strength = strength + 5;
    defense = defense + 5;
}

inline Healer::Healer()
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
inline void Character::specialMove()
{
//will add more to special move when we know what the special moves should do
}

inline void Warrior::specialMove()
{
//will add more to special move when we know what the special moves should do
}

inline void Healer::specialMove()
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
