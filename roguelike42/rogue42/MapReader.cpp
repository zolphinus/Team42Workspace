#include "MapReader.h"

MapReader::MapReader(string FileName)
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


    mapWindow = newwin(MAP_WINDOW_HEIGHT,MAP_WINDOW_WIDTH,0,0);//creates the window

}

MapReader::~MapReader(){
    delwin(mapWindow);
}

void MapReader::PrintWindow(int characterPosY, int characterPosX)
{
    int startPrintY=4, startPrintX=6, xShift, yShift;
    int YHolder, XHolder;

    /*if(characterPosX<6)
    {
        startPrintX=6;
    }
    else if(characterPosX+32>139)
    {
        startPrintX=76;
    }
    else
    {
        startPrintX=characterPosX;
    }*/

    startPrintX = characterPosX;
    startPrintX -= 25;

    /*if(characterPosY<4)
    {
        startPrintY=4;
    }
    else if(characterPosY+9>32)
    {
        startPrintY=15;
    }
    else
    {
        startPrintY=characterPosY;
    }*/

    startPrintY=characterPosY;
    startPrintY -= 8;

    init_pair(1,COLOR_RED,COLOR_WHITE);//----Initialize color pair
    wbkgd(mapWindow, COLOR_PAIR(1));

    for(int column=0; column<63; column ++)
    {
        for(int row=0; row<17; row++)
        {
            YHolder = startPrintY + row;
            if (YHolder > 31){
                YHolder = 31;
            }
            if (YHolder < 0){
                YHolder = 0;
            }




            XHolder = startPrintX + column;
            if (XHolder > 139){
                XHolder = 139;
            }

            if (XHolder < 0){
                XHolder = 0;
            }

            wmove(mapWindow, row,column);
            waddch(mapWindow, floorMap[YHolder][XHolder]);
        }
    }
    wrefresh(mapWindow);//Pushes changes to the screen
}

char MapReader::atPosition(int yToCheck, int xToCheck)
{
    return floorMap[yToCheck][xToCheck];
}


WINDOW* MapReader::getMapReader(){
    return mapWindow;
}
