#include "MapReader.h"
#include "MessageWindow.h"
using namespace std;

int main()
{
    MapReader mapReader("map0.txt");
    mapReader.PrintWindow(10,28);//(y,x) just like most of curses

    return 0;
}
