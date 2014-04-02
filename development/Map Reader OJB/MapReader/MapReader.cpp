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
}

void MapReader::PrintWindow(int CharacterY, int CharacterX)
{
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
            waddch(MapWindow, floorMap[row+CharacterY][column+CharacterX]);
        }// END ROW FORLOOP
    }// END COLUMN FORLOOP
    wrefresh(MapWindow);//Pushes changes to the screen

    WINDOW *MessageWindow = newwin(8,80,17,0);
    wbkgd(MessageWindow, COLOR_PAIR(2));
    wmove(MessageWindow, 0,0);
    waddstr(MessageWindow, "This is club kick Adam out!");
    wrefresh(MessageWindow);
    wgetch(MessageWindow);
    endwin();
}

