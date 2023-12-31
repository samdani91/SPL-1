#include<bits/stdc++.h>
#include "/home/samdani1412/Desktop/SPL-1/interpret.h"
#include "/home/samdani1412/Desktop/SPL-1/interpretFunc.cpp"
using namespace std;


int findLineNum(ifstream& inputFile);
void  moveFilePointer(fstream& inputFile,int readLinenum);
void compile_execute();
void writeBlock(fstream& file3,fstream& file4);

int main()
{

    ifstream file("/home/samdani1412/Desktop/SPL-1/Dynamic Analysis/sourceCodeDA.c");

    if(!(file.is_open())){
        cout<<"Error in opening Source Code file"<<endl;
        return 0;
    }

    ifstream file2("/home/samdani1412/Desktop/SPL-1/Dynamic Analysis/testCode.c");

    int writeLineNum=findLineNum(file2);

    file2.close();

    int readLineNum=findLineNum(file);
    file.close();

    fstream file3("/home/samdani1412/Desktop/SPL-1/Dynamic Analysis/sourceCodeDA.c");
    moveFilePointer(file3,readLineNum);


    string line;

    vector<string> testFile;
    ifstream f2("/home/samdani1412/Desktop/SPL-1/Dynamic Analysis/testCode.c");
    string line2;

    while(!f2.eof())
    {
        getline(f2,line2);
        testFile.push_back(line2);
    }

    f2.close();

    while(!file3.eof())
    {
        getline(file3,line);
        if(line.find("return 0;")!=string::npos) break;
        if(line.find("for(")!=string::npos or line.find("while(")!=string::npos or line.find("if(")!=string::npos or line.find("else")!=string::npos)
        {   
            testFile.insert(testFile.end()-3,line);
            while(line.find("}")==string::npos)
            {
                getline(file3,line);
                testFile.insert(testFile.end()-3,line);
            }
        }
        else
        {
            testFile.insert(testFile.end()-3,line);
        }
        for(auto it:testFile) cout<<it<<endl;
        ofstream w("/home/samdani1412/Desktop/SPL-1/Dynamic Analysis/testCode.c");
        for(auto it:testFile)
        {
            w<<it<<endl;
        }
        compile_execute();     
    }
    
    
    cout<<endl;
    
    return 0;
}

void compile_execute()
{
    int compileResult = system("gcc testCode.c -o da_exe");
    
    if(compileResult == 0){
        int executionResult = system("./da_exe");
        if(executionResult != 0){
            cout << "\nExecution failed." << endl;
        }
        
    }else{
        cout << "\nCompilation failed." << endl;
    }
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
        if(currLineNum==readLinenum-1){
            break;
        }
        currLineNum++;
    }
}

void writeBlock(fstream& file3,fstream& file4)
{   
    string line;
    getline(file3,line);
    while((line.find("}")==string::npos)){   
        file4<<line<<endl;
        getline(file3,line);
    }
    file4<<line<<endl;
}