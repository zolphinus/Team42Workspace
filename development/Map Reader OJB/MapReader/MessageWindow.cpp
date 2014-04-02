#include "MessageWindow.h"

MessageWindow::MessageWindow()
{
    UserMessages.resize(8);


}

void MessageWindow::AddMessage(string stringToAdd)
{
    UserMessages.insert(1,  stringToAdd);
    UserMessages.pop_back();

}

void MessageWindow::PrintMessageWindow()
{
    while(true)
    {
        if(UserMessages.size()>8)
        {
            UserMessages.pop_back(1);
        }
        else
        {
            break;
        }
    }

    initscr();//-------------------------curses stuff
    cbreak();//--------------------------disables the buffer
    curs_set(0);//-----------------------makes cursor invisible
    start_color();//---------------------must be run before using color

    init_pair(2,COLOR_WHITE,COLOR_BLUE);

    WINDOW *MessageWindow = newwin(MESSAGE_WINDOW_HEIGHT,MESSAGE_WINDOW_WIDTH,17,0);
    wbkgd(MessageWindow, COLOR_PAIR(2));

    for(int rowCounter = 8, vectorPos = 0; rowCounter>0; rowCounter--,vectorPos++)
    {
        wmove(MessageWindow, rowCounter,0);
        waddstr(MessageWindow, UserMessages[vectorPos]);
    }

    wrefresh(MessageWindow);
    wgetch(MessageWindow);
    endwin();
}
