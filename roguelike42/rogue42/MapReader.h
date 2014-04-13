#ifndef MAPREADER_H_INCLUDED
#define MAPREADER_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <curses.h>
using namespace std;

#define MAP_WINDOW_HEIGHT 17
#define MAP_WINDOW_WIDTH  63

class MapReader
{
public:
    MapReader(string);
    ~MapReader();
    void PrintWindow(int,int);
    char floorMap[32][139];
    char atPosition(int,int);//(y,x) like all of curse
    WINDOW* getMapReader();

private:
    WINDOW *mapWindow;
    ifstream mapFile;

};

#endif // MAPREADER_H_INCLUDED
