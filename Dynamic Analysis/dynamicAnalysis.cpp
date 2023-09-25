#include<bits/stdc++.h>
using namespace std;

int main()
{


    ifstream file2("testCode.c");

    if(!(file2.is_open())){
        cout<<"Error in opening file"<<endl;
        return 0;
    }

    string line;
    bool isMainWithout=false;
    bool isMainWith=false;
    int lineNum=0,targetLineNum;
    while(!file2.eof()){

        getline(file2,line);
        lineNum++; 

        if(line.find("main")!=string::npos && line.find("{")==string::npos){
            isMainWithout=true;
        }else if(line.find("main")!=string::npos && line.find("{")!=string::npos){
            isMainWith=true;
        }

        if(isMainWithout){
            lineNum++;
            getline(file2,line);
            lineNum++;
            if(line.find("{")!=string::npos){
                targetLineNum=lineNum;
                isMainWithout=false;
            }
        }else if(isMainWith){
            lineNum++;
            targetLineNum=lineNum;
            isMainWith=false;
        }

        // lineNum++;
    }
    cout<<targetLineNum<<endl;

    return 0;
}