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
    void PrintWindow(int,int);
    char floorMap[500][500];
    #define MAP_WINDOW_HEIGHT 17
    #define MAP_WINDOW_WIDTH  35
private:

    ifstream mapFile;

};

#endif // MAPREADER_H_INCLUDED
