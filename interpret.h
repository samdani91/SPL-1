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

vector<string> header = {"stdio.h", "conio.h", "stdlib.h", "math.h", "string.h"};
map<string, string> operators = {{"!=", "not equal "},
                                 {"==", "equal "},
                                 {">=", "greater than or equal "},
                                 {"<=", "less than or equal "},
                                 {">", "greater than "},
                                 {"<", "less than "}};
unordered_map<string, float> traceVar;

#endif