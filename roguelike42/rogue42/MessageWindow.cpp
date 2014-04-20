#include "MessageWindow.h"
#include "curses.h"

MessageWindow::MessageWindow()
{
    for(int arrayInitializer = 0; arrayInitializer<8; arrayInitializer++)
    {
        MessageArray[arrayInitializer] = "";
    }

    messageWindow = newwin(MESSAGE_WINDOW_HEIGHT,MESSAGE_WINDOW_WIDTH,17,0);

}

MessageWindow::~MessageWindow()
{
    delwin(messageWindow);
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
    //Displays the window with all blank spaces so when we print messages, it cleans up the trash automatically
    werase(messageWindow);

    init_pair(2,COLOR_RED,COLOR_BLACK);


    wbkgd(messageWindow, COLOR_PAIR(2));



    for(int rowCounter = 7, arrayPos = 0; rowCounter>0; rowCounter--,arrayPos++)//This dual variable for loop prints bottom to top
    {                                                                           //and reads the array top to bottom
        wmove(messageWindow, rowCounter,0);
        waddstr(messageWindow, MessageArray[arrayPos].c_str());
    }

    //wgetch(messageWindow);   //shouldn't need this if we control the flow of our window properly
    wrefresh(messageWindow);
}

WINDOW* MessageWindow::getMessageWindow(){
    return messageWindow;
}
