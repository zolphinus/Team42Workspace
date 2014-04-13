#ifndef MESSAGEWINDOW_H_INCLUDED
#define MESSAGEWINDOW_H_INCLUDED

#include <string>
#include <iostream>
#include <curses.h>
#include <vector>

#define MESSAGE_WINDOW_HEIGHT 8
#define MESSAGE_WINDOW_WIDTH 80

using namespace std;

class MessageWindow
{
public:
    MessageWindow();
    ~MessageWindow();
    void AddMessage(string);
    void PrintMessageWindow();
    WINDOW* getMessageWindow();


private:
    string MessageArray[8];
    WINDOW* messageWindow;
};


#endif // MESSAGEWINDOW_H_INCLUDED
