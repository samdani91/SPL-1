#include <bits/stdc++.h>
#include "TokenHeader.h"
using namespace std;

perLinestruct perline[2000];

string getPrintString(string item, int l, int col)
{
    string toR;
    if (isItInteger(item))
    {
        toR = "integer\t" + item + "\t" + intTostr(perline[l].line) + "\t";
        toR += intTostr(col - (item.size()) + 1) + "\n";
    }
    else if (isItDouble(item))
    {
        toR = "double\t" + item + "\t" + intTostr(perline[l].line) + "\t";
        toR += intTostr(col - (item.size()) + 1) + "\n";
    }
    else
    {
        toR = "identifier\t" + item + "\t" + to_string(perline[l].line) + "\t";
        toR += to_string(col - (item.size()) + 1) + "\n";
    }
    return toR;
}