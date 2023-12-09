#include<bits/stdc++.h>
#include "interpret.h"
using namespace std;

vector<string>allFunc={"strcpy","strcat","strlen","strcmp"};

void readStringFunction(string line, int lineNum)
{
    string func,str1,str2;
    int i=0;
    while(line[i]!='('){
        func+=line[i];
        i++;
    }
    i++;
    if(func==allFunc[0] or func==allFunc[1] or func==allFunc[3]){
        while(line[i]!=','){
            str1+=line[i];
            i++;
        }
        i++;
        while(line[i]!=')'){
            str2+=line[i];
            i++;
        }
        if(func==allFunc[0]){
            cout << "In line " << lineNum+1 << " >> "
                << "String copy function 'strcpy()' and copy the string " <<str2<<" to string "<<str1<<endl;
        }
        else if(func==allFunc[1]){
            cout << "In line " << lineNum+1 << " >> "
                << "String Concatenation function 'strcat()' which concatenate  the string " <<str2<<" to string "<<str1<<endl;
        }
    }else{
        cout<<"Under Construction.......";
    }
}