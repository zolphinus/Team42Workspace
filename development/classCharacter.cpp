#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class character{
public:
    character(); //used when making player character
    character(string enemy); //used only when creating enemies
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


/*I don't think using inheritance is going to work out very well here.  I am beginning to believe that we should simply
ask the user for their job in the character generation function and adjusts the stats accordingly.  Then, we can have a
variable that determines what special abilities the character will have.  For example, we could make a function
specialAbility().  What it does could depend on the variable mentioned earlier, the one that is determined by job.

Any thoughts?
*/
class warrior: public character
{
public:
    void hello()//test function
    {
        cout << "Hello" << endl;
    }
};

class healer: public character
{

};

character generateChar();
character generateRanChar();

int main()
{
    character player = generateChar();
    character* hero = &player;

    cout << hero -> getName() << endl;
    cout << hero -> getCurHP() << endl;
    cout << hero -> getStr() << endl;

    return 0;
}

character generateChar()
{
    character player;
    string playerName;
    int jobChoice;

    cout << "What is your name?" << endl;
    cin >> playerName;
    player.setName(playerName);

    cout << "Choose your job class" << endl;
    cout << "1. Warrior - Focuses on physical strength" << endl;
    cout << "2. Healer - Focuses on healing" << endl;
    cin >> jobChoice;

    if (jobChoice == 1)
    {
        warrior player;
        player.setName(playerName);
        player.setStr(10);
        player.setSpd(1);
        player.setMaxHP(150);
        player.setCurHP(150);
    }
    else if (jobChoice == 2)
    {
        healer player;
        player.setName(playerName);
        player.setStr(5);
        player.setSpd(1);
        player.setMaxHP(100);
        player.setCurHP(100);
    }

    return player;
}

character generateRanChar()
{

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
