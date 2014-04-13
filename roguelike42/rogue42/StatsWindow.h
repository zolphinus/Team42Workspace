#ifndef STATSWINDOW_H_INCLUDED
#define STATSWINDOW_H_INCLUDED

#include <string>
#include <iostream>
#include <curses.h>
#include <vector>

using namespace std;

class Character;

class StatsWindow
{
public:
    StatsWindow();
    ~StatsWindow();
    void PrintStatsWindow(Character*);


    #define STATUS_WINDOW_HEIGHT 17
    #define STATUS_WINDOW_WIDTH 17
private:
    string StatusArray[STATUS_WINDOW_HEIGHT];
    WINDOW* statusWindow;
};

#endif // STATSWINDOW_H_INCLUDED
