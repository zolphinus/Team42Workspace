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

int Character::getLevel(){
    return level;
}

void Character::setJobTitle(string newJob){
    this->jobName = newJob;
}

string Character::getJobTitle(){
    return jobName;
}

void Character::levelUp()
{
    if (expPoints >= 100)
    {
        int hpIncrease = rand() % 15 + 5;
        int spIncrease = rand() % 5;

        maxHP = maxHP + hpIncrease;
        maxSP = maxSP + spIncrease;

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
        for (int i = 1; i < 4; i++)
        {
            int strIncrease = rand() % 1;
            int defIncrease = rand() % 1;
            int spdIncrease = rand() % 1;

            strength = strength + strIncrease;
            defense = defense + defIncrease;
            speed = speed + spdIncrease;
        }

        level = level + 1;
        expPoints = expPoints - 100;

        if (maxHP > maxPossibleHP)
        {
            maxHP = maxPossibleHP;
        }

    }//end if 100 EXP loop
}

int Character::attack(Character* opponent)
{
    int damage;
    int priority;

    for (int i = 0; i < heldGear.size(); i++)//applying gear's stat bonuses
    {
        strength = strength + heldGear[i] -> getStrBuff();
        defense = defense + heldGear[i] -> getDefBuff();
        speed = speed + heldGear[i] -> getSpdBuff();
    }

    if(this->speed > opponent->getSpd())
    {
        priority = 0;

    }
    else if(this->speed < opponent->getSpd())
    {
        priority = 1;
    }
    else

    {
        priority = rand() % 2;
    }

    switch(priority){
        //Hit opponent first
    case 0:
        if (currentHP > 0)
        {
            damage = this->strength - opponent->getDef();
            if(damage <= 0)
                damage = 1;

            opponent->setCurHP(opponent->getCurHP() - damage);
        }
        if (opponent->getCurHP() > 0)
        {
            damage = opponent->getStr() - defense;
            if(damage <= 0)
                damage = 1;

            this->currentHP = this->currentHP - damage;
        }
        break;
    case 1:
        if (opponent->getCurHP() > 0)
        {
            damage = opponent->getStr() - this->defense;
            if(damage <= 0)
                damage = 1;

            this->currentHP = this->currentHP - damage;

        }

        if (this->currentHP > 0)
        {
            damage = this->strength - opponent->getDef();
            if(damage <= 0)
                damage = 1;

            opponent->setCurHP(opponent->getCurHP() - damage);

        }
        break;
    default :
        break;
    }

    for (int i = 0; i < heldGear.size(); i++)//unapplying gear's stat bonuses
    {
        strength = strength - heldGear[i] -> getStrBuff();
        defense = defense - heldGear[i] -> getDefBuff();
        speed = speed - heldGear[i] -> getSpdBuff();
    }

    return damage;
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

string Character::getEquippedItem(itemType typeToFind)
{
    string tempString = "";

    for (int i = 0; i < heldGear.size(); i++)
    {
        if (heldGear[i] -> getType() == typeToFind)
        {
            tempString = heldGear[i] -> getName();
        }
    }

    return tempString;
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

bool Character::equipGear(Item* newGear)
{
    if(newGear != NULL){
    //first check if the item to be equipped is gear
    if (newGear -> getType() != D && newGear -> getType() != P)
    {
        //Then check if you already have that type of gear equipped
        for(int i = 0; i < heldGear.size(); i++)
        {
            if (newGear -> getType() == heldGear[i] -> getType())
            {
                return false;
            }
        }

        //if you don't have the type of gear equipped, equip the new gear
        heldGear.push_back(newGear);
        maxHP = maxHP + newGear -> getHPBuff();
        maxSP = maxSP + newGear -> getSPBuff();
        removeInventory(newGear);
        return true;
    }
    else
    {
        return false;
    }
    }

    return false;
}

bool Character::unequipGear(int location)
{
    if (location < heldGear.size() && location > 0)
    {
        //If inventory isn't full, moves gear to bag. Else, cannot make action.
        if(inventory.size() < maxInventorySize){
            inventory.push_back(heldGear[location]);
            heldGear.erase(heldGear.begin() + location);
            return true;
        }
        else
            return false;
    }
    else
    {
        return false;
    }
    //May edit later to try and push unequipped gear into inventory
}

int Character::getMaxInventorySize(){
    return maxInventorySize;
}



bool Character::pickUp(Item* newItem)
{
    if(newItem != NULL){
        if (inventory.size() < maxInventorySize)//check if inventory is full
        {
            inventory.push_back(newItem);//if not, add item to inventory

            return true;
        }
    }

    return false;
}

Item* Character::dropItem(int location)
{
    Item* tempItem = NULL;

    if (location < inventory.size() && location >= 0)
    {
        tempItem = inventory[location];
        inventory.erase(inventory.begin() + location);
    }

    return tempItem;
}

//Implement into button presses
bool Character::useItem(int location)
{
    if(inventory.size() > 0)
    {
        if (inventory[location] -> getType() == P)//only works if the item is a healing item
        {
            currentHP = currentHP + inventory[location] -> getHPHeal();
            currentSP = currentSP + inventory[location] -> getSPHeal();

            removeInventory(inventory[location]);

            if(currentHP > maxHP)
            {
                currentHP = maxHP;
            }

            if(currentSP > maxSP)
            {
                currentSP = maxSP;
            }

            return true;
        }

        else
        {
            return false;
        }
    }

    return false;
}


Character::~Character()
{
}


Player::Player()
{
    //No longer need empty items populated :)
}


Warrior::Warrior()
{
    maxHP = maxHP + 30;
    currentHP = maxHP;
    strength = strength + 5;
    defense = defense + 5;
    jobName = "Warrior";
}


Healer::Healer()
{
    strength = strength - 3;
    defense = defense - 2;
    maxHP = maxHP - 20;
    currentHP = maxHP;
    jobName = "Healer";
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
    expPoints = 18;

}


void Character::specialMove()
{
}


void Warrior::specialMove()
{
    //Gives user a permanant strength buff
    if (currentSP >= 40)
    {
        strength = strength + rand() % 2 + 1;

        currentSP = currentSP - 40;
    }
}


void Healer::specialMove()
{
    //Heals user
    if (currentSP >= 20)
    {
        currentHP = currentHP + 80;

        if (currentHP > maxHP)
        {
            currentHP = maxHP;
        }

        currentSP = currentSP - 12;
    }
}

Item* Character::getInventory(int slotValue){

    if(inventory.size()> 0 && slotValue < inventory.size()){
        return inventory[slotValue];
    }
    return NULL;
}

Item* Character::getEquipment(int slotValue){

    if(heldGear.size()> 0 && slotValue < heldGear.size()){
        return heldGear[slotValue];
    }
    return NULL;
}


void Character::removeInventory(Item* tempItem){

    if(tempItem != NULL){
        for(int i = 0; i < inventory.size(); i++){
            if(tempItem == inventory[i]){
                inventory.erase(inventory.begin() + i);
            }

        }
    }
}

int Character::getEquipSize(){
    return heldGear.size();
}
