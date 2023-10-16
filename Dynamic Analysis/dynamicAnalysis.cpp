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

    ifstream file("/home/samdani1412/Desktop/SPL-1/sourceCode.c");

    if(!(file.is_open())){
        cout<<"Error in opening Source Code file"<<endl;
        return 0;
    }

    ifstream file2("da.c");

    int writeLineNum=findLineNum(file2);

    file2.close();

    int readLineNum=findLineNum(file);
    file.close();

    fstream file3("/home/samdani1412/Desktop/SPL-1/sourceCode.c");
    moveFilePointer(file3,readLineNum);

    fstream file4("da.c");
    moveFilePointer(file4,writeLineNum);

    string line;

    while(!file3.eof()){
        getline(file3,line);
        if(file3.eof()) continue;
    
        if(line.find("for(")!=string::npos or line.find("while(")!=string::npos or line.find("if(")!=string::npos or line.find("else")!=string::npos){;
            file4<<line<<endl;
            writeBlock(file3,file4);
            continue;
        }
        
        file4<<line<<endl<<"}";
        file4.seekp(-1, ios_base::end);
        
    }
    
    
    cout<<endl;
    
    return 0;
}

void compile_execute()
{
    int compileResult = system("gcc da.c -o da_exe");
    
    if(compileResult == 0){
        //cout << "\nCompilation successful. Running da_exe..." << endl;
        int executionResult = system("./da_exe"); // Execute the compiled program
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