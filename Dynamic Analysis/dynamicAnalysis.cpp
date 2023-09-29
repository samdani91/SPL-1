#include<bits/stdc++.h>
#include "/home/samdani1412/Desktop/temp/SPL/interpret.h"
#include "/home/samdani1412/Desktop/temp/SPL/interpretFunc.cpp"
using namespace std;


int findLineNum(ifstream& inputFile);
void  moveFilePointer(fstream& inputFile,int readLinenum);

int main()
{

    ifstream file("/home/samdani1412/Desktop/temp/SPL/sourceCode.c");

    if(!(file.is_open())){
        cout<<"Error in opening Source Code file"<<endl;
        return 0;
    }

    ifstream file2("da.c");

    int writeLineNum=findLineNum(file2);

    file2.close();

    int readLineNum=findLineNum(file);
    file.close();

    fstream file3("/home/samdani1412/Desktop/temp/SPL/sourceCode.c");
    moveFilePointer(file3,readLineNum);

    fstream file4("da.c");
    moveFilePointer(file4,writeLineNum);

    string line;

    while(getline(file3,line)){
        file4<<line<<endl;
    }
    

    

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
void  moveFilePointer(fstream& inputFile,int readLinenum)
{
    string line;
    int currLineNum=1;
    while(getline(inputFile,line)){
        //cout<<line<<endl;
        if(currLineNum==readLinenum-1){
            break;
        }
        currLineNum++;
    }
    //return inputFile;
}