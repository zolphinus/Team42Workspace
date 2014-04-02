#ifndef MESSAGEWINDOW_H_INCLUDED
#define MESSAGEWINDOW_H_INCLUDED

#include <string>
#include <iostream>
#include <curses.h>
#include <vector>

using namespace std;

class MessageWindow
{
public:
    MessageWindow();
    void AddMessage(string);
    void PrintMessageWindow();
    #define MESSAGE_WINDOW_HEIGHT 8
    #define MESSAGE_WINDOW_WIDTH 80
private:
    vector<string> UserMessages;
};


#endif // MESSAGEWINDOW_H_INCLUDED
