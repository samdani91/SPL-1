#include<bits/stdc++.h>
#include "interpret.h"
using namespace std;

void check_semi_colon(unordered_multimap<string, string> statement, int lineNum)
{
    
    bool isSemiColon=false;
    auto range=statement.equal_range("operator");

    for(auto it=range.first;it!=range.second;it++){
        string temp=it->second;
        if(temp==";"){
            isSemiColon=true;
        }
    }

    if(!isSemiColon){
        cout <<"\033[1;31m\t\terror: expected ';'"<<endl;
        cout << "\033[0m";
    }
}