#ifndef MAPREADER_H_INCLUDED
#define MAPREADER_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <curses.h>
using namespace std;

class MapReader
{
public:
    MapReader(string);
    ~MapReader();
    void PrintWindow(int,int);
    char floorMap[500][500];
    char atPosition(int,int);//(y,x) like all of curse
    #define MAP_WINDOW_HEIGHT 17
    #define MAP_WINDOW_WIDTH  35
private:
    WINDOW *mapWindow;
    ifstream mapFile;

};

#endif // MAPREADER_H_INCLUDED
