#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class character{
public:
    character();
    character(string enemy);
    void setMaxHP(int newHP);
    int getMaxHP();
    void setCurHP(int newHP);
    int getCurHP();
    void setStr(int newStr);
    int getStr();
    void setSpd(int newSpd);
    int getSpd();
    void setName(string playerName);
    string getName();
private:
    int currentHP;
    int maxHP;
    int strength;
    int speed;
    string name;
};

character generateChar()
{
    string playerName;
    string userChoice;

    cout << "What is your name?" << endl;
    cin >> playerName;

    cout << "Do you want to randomize your character?  Y/N" << endl;
    cin >> userChoice;

    if (userChoice == "Y" || userChoice == "y")
    {
        //randomize class

    }

    else if (userChoice == "N" || userChoice == "n")
    {
        int jobChoice;
        cout << "Choose your job class" << endl;
        cout << "1. Warrior - Focuses on physical strength" << endl;
        cout << "2. Healer - Focuses on healing" << endl;
        cin >> jobChoice;

        if (jobChoice == 1)
        {
            //adjust stats based on class chosen
        }
        else if (jobChoice == 2)
        {
            //adjust stats based on class chosen
        }
    }

    else
    {

    }
}

int main()
{
    character bob;
    return 0;
}

character::character()
{
    cout << "Created character" << endl;
}

character::character(string enemy)
{
    name = enemy;
    //Will the stats for enemies always be randomized?
}

void character::setMaxHP(int newHP)
{
    maxHP = newHP;
}

int character::getMaxHP()
{
    return maxHP;
}

void character::setCurHP(int newHP)
{
    currentHP = newHP;
}

int character::getCurHP()
{
    return currentHP;
}

void character::setStr(int newStr)
{
    strength = newStr;
}

int character::getStr()
{
    return strength;
}

void character::setSpd(int newSpd)
{
    speed = newSpd;
}

int character::getSpd()
{
    return speed;
}

void character::setName(string playerName)
{
    name = playerName;
}

string character::getName()
{
    return name;
}
