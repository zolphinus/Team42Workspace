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

I'm thinking the best way to handle the inheritance would be to make the character class,
and make the inherited "Jobs". I can make a function in the controller class that can generate "what class", and that may be
easier with how inheritance works in C++ anyways.

If you make the "stats" protected instead of private, then the derived classes (jobs) can directly access them.
So the "character" generates "base stats", and the "jobs" just need to "add to them".

Example:

character may have 

int strength = rand() % 5 + 5 (random range 5 t 9).
int mana = rand() % 5 + 10 (random from 10 to 14).

Then a warrior would have

strength = strength + 4; (effectively changes the starting range to "9 to 13")
mana = mana - 8; (effectively changes the starting range to "2 to 6")

While a mage may have

strength = strength -3; (range "2 to 6")
mana = mana + 10; (range "20 to 24")




And then, the character can have a method "specialMove()" that we simply overload in the "jobs". This way we can
simply call one function name for all of the derived classes, even though we would need to define the ability for each class.


As a side note for technical stuffs, are you familiar with how to use header files?
If not, I'll be happy to assist, they work a bit differently with inheritance, and that requires a bit of work around,
but cleans up and compartmentalizes the code.


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
