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
}

void MapReader::PrintWindow(int CharacterPosY, int CharacterPosX)
{
    int startPrintY=9, startPrintX=19;

    if(CharacterPosY<9)
    {
        startPrintY = 0;         //Keeps from printing junk
    }
    else if(CharacterPosX<19)
    {
        startPrintX = 0;
    }
    else
    {
        startPrintY=CharacterPosY;
        startPrintX=CharacterPosX;
    }



    initscr();//-------------------------curses stuff
    cbreak();//--------------------------disables the buffer
    curs_set(0);//-----------------------makes cursor invisible
    start_color();//---------------------must be run before using color
    init_pair(1,COLOR_RED,COLOR_WHITE);//----Initialize color pair
    WINDOW *MapWindow = newwin(MAP_WINDOW_HEIGHT,MAP_WINDOW_WIDTH,0,0);//creates the window
    wbkgd(MapWindow, COLOR_PAIR(1));

    for(int column=0; column<MAP_WINDOW_WIDTH; column++)
    {
        for(int row=0; row<MAP_WINDOW_HEIGHT; row++)
        {
            wmove(MapWindow, row, column);//------moves the cursor and prints the character in the floormap
            waddch(MapWindow, floorMap[row+startPrintY][column+startPrintX-19]);
        }// END ROW FORLOOP
    }// END COLUMN FORLOOP
    wrefresh(MapWindow);//Pushes changes to the screen
}

char MapReader::atPosition(int yToCheck, int xToCheck)
{
    return floorMap[yToCheck][xToCheck];
}
