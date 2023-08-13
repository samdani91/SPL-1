#ifndef HEADERFILE_H
#define HEADERFILE_H

#include<bits/stdc++.h>
using namespace std;

struct perLinestruct{
    int line;
    string text;
};

string trim_left( string st, char ch );
string trim_right( string st, char ch );
string trim_both( string st, char ch );
bool isDigit( char ch );
bool isCapitalLetter( char ch );
bool isSmallLetter( char ch );
bool isLetter( char ch );
bool isNumber( string str );
string intTostr( int number );
int strToint( string str );
bool validVariableName( string str );
bool operatorCheck( char ch );
bool operatorCheckdouble( char ch );
bool isItInteger( string check );
bool isItDouble( string check );


#endif