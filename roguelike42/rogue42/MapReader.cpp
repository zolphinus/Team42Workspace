#include "MapReader.h"

MapReader::MapReader(string FileName)
{
    mapWindow = newwin(MAP_WINDOW_HEIGHT,MAP_WINDOW_WIDTH,0,0);//creates the window
    ReadMap(FileName);
}

MapReader::~MapReader(){
    delwin(mapWindow);
}

void MapReader::ReadMap(string FileName)
{
    ifstream mapIn;
    string getlineHolder;
    int rowMarker = 0;
    char *cstr = new char[FileName.length()+1];          // converts the string into usable format for opening
    strcpy(cstr, FileName.c_str());
    mapIn.open(cstr);

    while (true)
    {
        getline(mapIn,getlineHolder);
        if (mapIn.good())
        {
            for(int columnMarker = 0; columnMarker<getlineHolder.length(); columnMarker ++)  //fills the floormap from the txt file
            {
                floorMap[rowMarker][columnMarker] = getlineHolder[columnMarker];
            }
        }
        else
        {
            break;
        }
        rowMarker++;
    }
    mapIn.close();
    delete cstr;
    cstr = NULL;
}

void MapReader::PrintWindow(int characterPosY, int characterPosX, std::vector <Enemy*> enemy, std::vector <Item*> item)
{
    bool enemyLocated = false;
    int startPrintY=8, startPrintX=25, xShift, yShift;
    int YHolder, XHolder;

    startPrintX = characterPosX;
    startPrintX -= 25;

    startPrintY=characterPosY;
    startPrintY -= 8;

    init_pair(1,COLOR_CYAN,COLOR_BLACK);//----Initialize color pair
    wbkgd(mapWindow, COLOR_PAIR(1));

    for(int column=20; column<31; column ++)
    {
        for(int row=4; row<13; row++)
        {
            YHolder = startPrintY + row;
            if (YHolder >= 31){
                YHolder = 0;
            }
            if (YHolder < 0){
                YHolder = 0;
            }

            XHolder = startPrintX + column;
            if (XHolder >= 139){
                XHolder = 0;
            }

            if (XHolder < 0){
                XHolder = 0;
            }

            wmove(mapWindow, row,column);

            if(floorMap[YHolder][XHolder] == '#')
            {
                waddch(mapWindow, '#');
            }
            else{

                waddch(mapWindow, floorMap[YHolder][XHolder]);

            }

            //updates enemies within fog
                if(item.size() > 0){
                for(int i = 0; i < item.size(); i++){

                    if(item[i]->getYPos() == YHolder
                       && item[i]->getXPos() == XHolder)
                    {
                        wmove(mapWindow, row,column);
                        waddch(mapWindow, 'I');
                    }

                }
                }

                if(enemy.size() > 0){
                for(int i = 0; i < enemy.size(); i++){
                    if(enemy[i]->getYPos() == YHolder
                       && enemy[i]->getXPos() == XHolder)
                    {
                        wmove(mapWindow, row,column);
                        waddch(mapWindow, 'E');
                    }
                }
                }
        }
    }

    wrefresh(mapWindow);//Pushes changes to the screen
}

char MapReader::atPosition(int yToCheck, int xToCheck)
{
    return floorMap[yToCheck][xToCheck];
}

void MapReader::setPosition(int yToSet, int xToSet, char newChar){
    floorMap[yToSet][xToSet] = newChar;
}


WINDOW* MapReader::getMapReader(){
    return mapWindow;
}
