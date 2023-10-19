#ifndef INTERPRET_H
#define INTERPRET_H

#include <bits/stdc++.h>
using namespace std;

void interpretation();
void read_headers(string line);
void read_main_prototype(string line, string tokenValue);
void check_open_bracket(int lineNum, string tokenValue,string keyword);
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
void readArray(unordered_map<string, string> statements, int lineNum);

#endif