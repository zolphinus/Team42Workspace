#include "MapReader.h"

using namespace std;

int main()
{

    MapReader mapReader("map0.txt");
    mapReader.PrintWindow(1,0);//(y,x) just like most of curses

    return 0;
}
