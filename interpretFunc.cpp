#include <bits/stdc++.h>
#include "interpret.h"
using namespace std;


bool open, isMain = false;

void interpretation()
{

    ifstream file("TokenFile.txt");

    if (!file.is_open())
    {
        cout << "Failed to open the file." << endl;
        return ;
    }

    string line, temp;
    
    getline(file, line);

    while (!file.eof())
    {

        istringstream iss(line);
        string tokenType, tokenValue, tempTokenValue;
        int lineNum, currlineNum;

        iss >> tokenType >> tokenValue >> lineNum;
        tempTokenValue = tokenValue;
        currlineNum = lineNum;

        if (tokenValue == "#")
        {
            while (currlineNum == lineNum)
            {
                read_headers(line);
                line.clear();
                getline(file, line);
                istringstream iss(line);
                iss >> tokenType >> tokenValue >> currlineNum;
            }
        }
        else if (tokenType == "keyword" && isMain == false)
        {
            while (currlineNum == lineNum)
            {
                line.clear();
                getline(file, line);
                istringstream iss(line);
                iss >> tokenType >> tokenValue >> currlineNum;
                read_main_prototype(line, tempTokenValue);
            }
        }
        else if (open == true)
        {
            check_open_bracket(lineNum, tokenValue);
        }
        else
        {
            // cout<<line<<endl;
            getline(file, line);
        }
    }

    return ;
}
void read_headers(string line)
{
    string tokenValue, tokenType;
    int lineNum;
    istringstream iss(line);
    iss >> tokenType >> tokenValue >> lineNum;
    for (int i = 0; i < header.size(); i++)
    {
        if (tokenValue == header[i])
        {
            cout << "In line " << lineNum + 1 << " >> " << tokenValue << " header file" << endl;
        }
    }
}

void read_main_prototype(string line, string tempTokenValue)
{
    string tokenValue, tokenType;
    int lineNum;
    istringstream iss(line);
    iss >> tokenType >> tokenValue >> lineNum;

    if (tokenValue == "main")
    {
        cout << "In line " << lineNum + 1 << " >> " << tokenValue << " function and return type " << tempTokenValue << endl;
        open = true;
        isMain = true;
    }
}
void check_open_bracket(int lineNum, string tokenValue)
{
    if (tokenValue == "{")
    {
        cout << "In line " << lineNum + 1 << " >> " << tokenValue << " opening curly braces of main function" << endl;
        open = false;
    }
}
void read_var(unordered_map<string, string> mp, int lineNum)
{
    auto it = mp.find("integer");
    if (it != mp.end())
    {
        cout << "In line " << lineNum + 1 << " >> "
             << "This a " << mp["keyword"] << " variable " << mp["identifier"] << " and value assigned to it is " << mp["integer"] << endl;
        traceVar.insert(make_pair(mp["identifier"], stoi(mp["integer"])));
    }
    else
    {
        it = mp.find("float");
        if (it != mp.end())
        {
            cout << "In line " << lineNum + 1 << " >> "
                 << "This a " << mp["keyword"] << " variable " << mp["identifier"] << " and value assigned to it is " << mp["float"] << endl;
            traceVar.insert(make_pair(mp["identifier"], stof(mp["float"])));
        }
    }
}
void read_condition(unordered_map<string, string> condition, int lineNum)
{
    auto it = condition.find("integer");
    int checkInt = 0;
    if (it != condition.end())
    {
        cout << "In line " << lineNum + 1 << " >> "
             << "There is a " << condition["keyword"] << " condition that is true when " << condition["identifier"] << " is " << operators[condition["operator"]] << condition["integer"] << endl;
        checkInt = 1;
    }
    else
    {
        it = condition.find("float");
        if (it != condition.end())
        {unordered_map<string, float> traceVar;
            cout << "In line " << lineNum + 1 << " >> "
                 << "There is a " << condition["keyword"] << " condition that is true when " << condition["identifier"] << " is " << operators[condition["operator"]] << condition["float"] << endl;
        }
    }
    float temp = traceVar[condition["identifier"]];
    float temp2;
    if (checkInt)
    {
        temp2 = stof(condition["integer"]);
    }
    else
    {
        temp2 = stof(condition["float"]);
    }
    if (condition["operator"] == "!=")
    {
        if (temp != temp2)
        {
            cout << "\t\tand Condition is true" << endl;
        }
        else
        {
            cout << "\t\tand Condition is false" << endl;
        }
    }
    else if (condition["operator"] == "==")
    {
        if (temp == temp2)
        {
            cout << "\t\tand Condition is true" << endl;
        }
        else
        {
            cout << "\t\tand Condition is false" << endl;
        }
    }
    else if (condition["operator"] == ">=")
    {
        if (temp >= temp2)
        {
            cout << "\t\tand Condition is true" << endl;
        }
        else
        {
            cout << "\t\tand Condition is false" << endl;
        }
    }
    else if (condition["operator"] == "<=")
    {
        if (temp <= temp2)
        {
            cout << "\t\tand Condition is true" << endl;
        }
        else
        {
            cout << "\t\tand Condition is false" << endl;
        }
    }
    else if (condition["operator"] == ">")
    {
        if (temp > temp2)
        {
            cout << "\t\tand Condition is true" << endl;
        }
        else
        {
            cout << "\t\tand Condition is false" << endl;
        }
    }
    else if (condition["operator"] == "<")
    {
        if (temp < temp2)
        {
            cout << "\t\tand Condition is true" << endl;
        }
        else
        {
            cout << "\t\tand Condition is false" << endl;
        }
    }
}