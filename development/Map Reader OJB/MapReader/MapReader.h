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
    char floorMap[500][500];
private:

    ifstream mapFile;

};

#endif // MAPREADER_H_INCLUDED
