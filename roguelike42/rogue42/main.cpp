#include <iostream>
#include "MapReader.h"
#include "MessageWindow.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout << "Hello world!" << endl;

    MapReader mapReader("map0.txt");
    MessageWindow messageWindow;
    messageWindow.AddMessage("compatability testing");
    mapReader.PrintWindow(0,0);
    messageWindow.PrintMessageWindow();



    return 0;
}
