#ifndef INTERPRET_H
#define INTERPRET_H

#include <bits/stdc++.h>
using namespace std;

void interpretation();
void read_headers(string line);
void read_main_prototype(string line, string tokenValue);
void check_open_bracket(int lineNum, string tokenValue,string keyword);
void read_inLineVar(set<string>vars,int lineNum);
void read_var(unordered_map<string, string> map, int currlineNum);
void read_condition(unordered_map<string, string> condition, int lineNum);
void read_if_else_block(unordered_multimap<string, string> statements, int lineNum);
void read_printf(unordered_multimap<string, string> print, int lineNum);
void read_scanf(unordered_multimap<string, string> input, int lineNum);
void read_for(unordered_map<string, string> statements, int lineNum);
void read_for_block(unordered_multimap<string, string> statements,unordered_map<string,string>condition,unordered_map<string,string>modification, int lineNum);
void read_while(unordered_map<string, string> statements, int lineNum);
void read_while_block(unordered_multimap<string, string> statements,unordered_map<string,string>condition,int lineNum);
bool isArray(unordered_multimap<string, string> map);
void readArray(unordered_multimap<string, string> statements, int lineNum);

void check_semi_colon(unordered_multimap<string, string> statement, int lineNum);
void check_Ampersand(unordered_multimap<string,string>statment,int lineNum);

void readStringFunction(string line, int lineNum);

void readArithmetic(string line,int lineNum);
void readAddition(string storeVar,string op1,string op2,int lineNum);
void readSubtraction(string storeVar,string op1,string op2,int lineNum);
void readMultiplication(string storeVar,string op1,string op2,int lineNum);
void readDivision(string storeVar,string op1,string op2,int lineNum);
void readRemainder(string storeVar,string op1,string op2,int lineNum);



#endif
