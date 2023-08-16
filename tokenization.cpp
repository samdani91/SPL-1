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
string keyword_identifier_number_check(int l, int col, string &item)
{
    if (item.size() == 0)
        return "";
    string keywords[32] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
                           "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short",
                           "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

    for (int k = 0; k < 32; k++)
    {
        if (item.compare(keywords[k]) == 0)
        {
            string toR = "keyword\t" + item + "\t" + to_string(perline[l].line) + "\t";
            toR += to_string(col - (item.size()) + 1) + "\n";
            item = "";
            return toR;
        }
    }
    string toR = getPrintString(item, l, col);
    item = "";
    return toR;
}
int inputCodeInLineByLine(string inputFile)
{
    int totalLine = 0;
    string part;

    stringstream X(inputFile);
    while (getline(X, part, '\n'))
    {
        perline[totalLine].text = part + " ";
        perline[totalLine++].line = totalLine;
    }

    return totalLine;
}