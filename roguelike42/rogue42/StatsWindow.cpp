#include "StatsWindow.h"
#include "curses.h"
#include "Character.h"
#include <sstream>

template <typename T>
    string NumberToString(T Number)
    {
        ostringstream ss;
        ss<<Number;
        return ss.str();
    }

StatsWindow::StatsWindow(Character* Hero)
{
    for(int arrayInitializer = 0; arrayInitializer<STATUS_WINDOW_HEIGHT; arrayInitializer++)
    {
        StatusArray[arrayInitializer] = "";
    }
    StatusArray[0]="Name: "+Hero->getName();
    StatusArray[1]="HP  : "+NumberToString(Hero->getCurHP())+"/"+NumberToString(Hero->getMaxHP());
    statusWindow = newwin(STATUS_WINDOW_HEIGHT,STATUS_WINDOW_WIDTH,0,35);

}

StatsWindow::~StatsWindow()
{

}

void StatsWindow::PrintStatsWindow(Character* Hero)
{
    string xPos, yPos, outString;
    werase(statusWindow);

    init_pair(3, COLOR_WHITE,COLOR_GREEN);

    wbkgd(statusWindow, COLOR_PAIR(3));

    for(int rowCounter = 0; rowCounter<STATUS_WINDOW_HEIGHT; rowCounter++)
    {
        wmove(statusWindow, rowCounter,0);
        waddstr(statusWindow, StatusArray[rowCounter].c_str());
    }

    /*
    xPos = char(Hero->getXPos());
    yPos = char(Hero->getYPos());
    outString = "HeroX:"+xPos+" HeroY:"+yPos;
    waddstr(statusWindow, outString.c_str());
    */

    wrefresh(statusWindow);
}
