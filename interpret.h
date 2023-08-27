#ifndef INTERPRET_H
#define INTERPRET_H

#include <bits/stdc++.h>
using namespace std;

void interpretation();
void read_headers(string line);
void read_main_prototype(string line, string tokenValue);
void check_open_bracket(int lineNum, string tokenValue);
void read_var(unordered_map<string, string> map, int currlineNum);
void read_condition(unordered_map<string, string> condition, int lineNum);
void read_if_else_block(unordered_multimap<string, string> statements, int lineNum);
void read_printf(unordered_multimap<string, string> print, int lineNum);

vector<string> header = {"stdio.h", "conio.h", "stdlib.h", "math.h", "string.h"};
map<string, string> operators = {{"!=", "not equal "},
                                 {"==", "equal "},
                                 {">=", "greater than or equal "},
                                 {"<=", "less than or equal "},
                                 {">", "greater than "},
                                 {"<", "less than "}};
map<string, string> fm_spec = {{"%d", "integer "},
                                {"%dn", "integer in every new line "},
                               {"%f", "float "},
                               {"%fn", "float in every new line "}};
unordered_map<string, float> traceVar;

#endif