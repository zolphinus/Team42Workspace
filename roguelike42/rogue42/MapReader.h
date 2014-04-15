#ifndef MAPREADER_H_INCLUDED
#define MAPREADER_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <curses.h>
#include <vector>
#include "Character.h"
#include "GameConfig.h"

using namespace std;




class MapReader
{
public:
    MapReader(string);
    ~MapReader();
    void PrintWindow(int,int, std::vector <Enemy*>, std::vector <Item*>);

    char floorMap[FLOOR_MAP_HEIGHT][FLOOR_MAP_WIDTH];
    char atPosition(int,int);//(y,x) like all of curse
    void setPosition(int,int, char);
    WINDOW* getMapReader();

private:
    WINDOW *mapWindow;
    ifstream mapFile;

};

#endif // MAPREADER_H_INCLUDED
