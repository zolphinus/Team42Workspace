#ifndef GLOBALFUNCTIONS_H_INCLUDED
#define GLOBALFUNCTIONS_H_INCLUDED

#include <sstream>
template <typename T>
string NumberToString(T Number)
    {
        ostringstream ss;
        ss<<Number;
        return ss.str();
    }

#endif // GLOBALFUNCTIONS_H_INCLUDED
