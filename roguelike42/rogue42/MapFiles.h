#ifndef MAP_FILES
#define MAP_FILES
#include <string>
#include "GameConfig.h"
#include "GlobalFunctions.h"

using std::string;

string randomMap(){
    int mapNumber = rand() % NUMBER_OF_MAPS;
    string mapName = "map" + NumberToString(mapNumber) + ".txt";
    return mapName;
}


#endif // MAP_FILES
