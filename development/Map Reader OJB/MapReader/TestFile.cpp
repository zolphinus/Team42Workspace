#include "MapReader.h"
#include "MessageWindow.h"
using namespace std;

int main()
{

    MapReader mapReader("map0.txt");
    MessageWindow messageWindow;
    mapReader.PrintWindow(-1,0);//(y,x) just like most of curses
    messageWindow.AddMessage("Adam is GONE!!");
    messageWindow.AddMessage("Adam is here?");
    messageWindow.AddMessage("42 is best team!");
    messageWindow.PrintMessageWindow();

    return 0;
}
