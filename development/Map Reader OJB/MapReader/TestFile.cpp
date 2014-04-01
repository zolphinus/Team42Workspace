#include "MapReader.h"

using namespace std;

int main()
{
    int offsetColumn=0, offsetRow=0; //These were for testing moving the view around

    MapReader mapReader("map0.txt");
    initscr();//-------------------------curses stuff
    curs_set(0);
    start_color();
    init_pair(1,COLOR_RED,COLOR_WHITE);
    WINDOW *MapWindow = newwin(17,25,0,0);//creates the window
    wbkgd(MapWindow, COLOR_PAIR(1));

    for(int column=0; column<25; column++)
    {
        for(int row=0; row<17; row++)
        {
            wmove(MapWindow, row, column);//        moves the cursor and prints the character in the floormap
            waddch(MapWindow, mapReader.floorMap[row+offsetRow][column+offsetColumn]);
            wrefresh(MapWindow);
        }
        wrefresh(MapWindow);
    }
    wgetch(MapWindow);
    endwin();
    return 0;
}
