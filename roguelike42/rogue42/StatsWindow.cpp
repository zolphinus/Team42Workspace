#include "StatsWindow.h"
#include "curses.h"
#include "Character.h"
#include "GlobalFunctions.h"


StatsWindow::StatsWindow()
{
    for(int arrayInitializer = 0; arrayInitializer<STATUS_WINDOW_HEIGHT; arrayInitializer++)
    {
        StatusArray[arrayInitializer] = "";
    }
    statusWindow = newwin(STATUS_WINDOW_HEIGHT,STATUS_WINDOW_WIDTH,0,63);

}

StatsWindow::~StatsWindow()
{
    delwin(statusWindow);
}

void StatsWindow::PrintStatsWindow(Character* Hero)
{
    StatusArray[0]="Name: "+Hero->getName();
    StatusArray[1] = "Lvl. " + NumberToString(Hero->getLevel()) + "  " + Hero->getJobTitle();
    StatusArray[2]="HP  : "+NumberToString(Hero->getCurHP())+"/"+NumberToString(Hero->getMaxHP());
    StatusArray[3]="SP  : "+NumberToString(Hero->getCurSP())+"/"+NumberToString(Hero->getMaxSP());
    StatusArray[5]="EXP : "+NumberToString(Hero->getEXP())+"/100";
    StatusArray[6]= Hero->getEquippedItem(W);
    StatusArray[7]= Hero->getEquippedItem(H);
    StatusArray[8]= Hero->getEquippedItem(R);
    StatusArray[9]= Hero->getEquippedItem(A);


    string xPos, yPos, outString;
    werase(statusWindow);

    init_pair(3, COLOR_GREEN,COLOR_BLACK);

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
