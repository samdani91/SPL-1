#include<bits/stdc++.h>
#include "/home/samdani1412/Desktop/SPL-1/interpret.h"
#include "/home/samdani1412/Desktop/SPL-1/interpretFunc.cpp"
using namespace std;


int findLineNum(ifstream& inputFile);
void  moveFilePointer(ifstream& inputFile,int readLinenum);

int main()
{

    ifstream file("/home/samdani1412/Desktop/SPL-1/sourceCode.c");

    if(!(file.is_open())){
        cout<<"Error in opening Source Code file"<<endl;
        return 0;
    }

    ifstream file2("/home/samdani1412/Desktop/SPL-1/Dynamic Analysis/testCode.c");

    int writeLineNum=findLineNum(file2);
    int readLineNum=findLineNum(file);
    file.close();

    ifstream file3("/home/samdani1412/Desktop/SPL-1/sourceCode.c");
    moveFilePointer(file3,readLineNum);

    string line;

    // while(getline(file3,line)){
    //     cout<<line<<endl;
    // }
    

    

    return 0;
}
int findLineNum(ifstream& inputFile)
{
    

    if(!(inputFile.is_open())){
        cout<<"Error in opening file"<<endl;
        return -1;
    }

    string line;
    bool isMainWithout=false;
    bool isMainWith=false;
    int lineNum=0,targetLineNum;

    while(getline(inputFile,line)){

        
        lineNum++; 

        if(line.find("main")!=string::npos && line.find("{")==string::npos){
            isMainWithout=true;
        }else if(line.find("main")!=string::npos && line.find("{")!=string::npos){
            isMainWith=true;
        }

        if(isMainWithout){
            lineNum++;
            getline(inputFile,line);
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

    }
    return targetLineNum;
}
void  moveFilePointer(ifstream& inputFile,int readLinenum)
{
    string line;
    int currLineNum=0;
    while(getline(inputFile,line)){
        cout<<line<<endl;
        if(currLineNum==readLinenum){
            break;
        }
        currLineNum++;
    }
    //return inputFile;
}