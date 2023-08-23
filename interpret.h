#include <bits/stdc++.h>
using namespace std;

void interpretation();
void read_headers(string line);
void read_main_prototype(string line, string tokenValue);
void check_open_bracket(int lineNum, string tokenValue);


vector<string> header = {"stdio.h", "conio.h", "stdlib.h", "math.h", "string.h"};