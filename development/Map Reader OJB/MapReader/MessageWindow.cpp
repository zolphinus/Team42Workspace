#include "MessageWindow.h"

MessageWindow::MessageWindow()
{
    for(int arrayInitializer = 0; arrayInitializer<8; arrayInitializer++)
    {
        MessageArray[arrayInitializer] = "";
    }


}

void MessageWindow::AddMessage(string stringToAdd)
{
    string messageMover = "", messageHolder="";
    messageHolder = MessageArray[6];
    for(int arrayCycler=7; arrayCycler>0; arrayCycler--)
    {
        messageMover = MessageArray[arrayCycler-1];
        MessageArray[arrayCycler] = messageMover;
    }
    MessageArray[0]=stringToAdd;
}

void MessageWindow::PrintMessageWindow()
{

    initscr();//-------------------------curses stuff
    cbreak();//--------------------------disables the buffer
    curs_set(0);//-----------------------makes cursor invisible
    start_color();//---------------------must be run before using color

    init_pair(2,COLOR_WHITE,COLOR_BLUE);

    WINDOW *MessageWindow = newwin(MESSAGE_WINDOW_HEIGHT,MESSAGE_WINDOW_WIDTH,17,0);
    wbkgd(MessageWindow, COLOR_PAIR(2));



    for(int rowCounter = 7, arrayPos = 0; rowCounter>0; rowCounter--,arrayPos++)//This dual variable for loop prints bottom to top
    {                                                                           //and reads the array top to bottom
        wmove(MessageWindow, rowCounter,0);
        waddstr(MessageWindow, MessageArray[arrayPos].c_str());
    }

    wgetch(MessageWindow);
    wrefresh(MessageWindow);
    endwin();
}
