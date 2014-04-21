#ifndef STATSWINDOW_H_INCLUDED
#define STATSWINDOW_H_INCLUDED

#include <string>
#include <iostream>
#include <curses.h>
#include <vector>
#include "GameConfig.h"

using namespace std;



class Character;

class StatsWindow
{
public:
    StatsWindow();
    ~StatsWindow();
    void PrintStatsWindow(Character*);

private:
    string StatusArray[STATUS_WINDOW_HEIGHT];
    WINDOW* statusWindow;
};

#endif // STATSWINDOW_H_INCLUDED
