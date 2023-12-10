#include<bits/stdc++.h>
#include "interpret.h"
using namespace std;

void readArithmetic(string line,int lineNum)
{   

    string operand1,operand2,op,storeVar;
    int i=0;
    while(line[i]!='='){
        storeVar+=line[i];
        i++;
    }
    
    i++;
    while(line[i]!='+' and line[i]!='-' and line[i]!='*' and line[i]!='/' and line[i]!='%'){
        operand1+=line[i];
        i++;
    }
    op=line[i];
    i++;
    while(line[i]!=';'){
        operand2+=line[i];
        i++;
    }

    if(op=="+"){
        readAddition(storeVar,operand1,operand2,lineNum);
    }
    else if(op=="-"){
        readSubtraction(storeVar,operand1,operand2,lineNum);
    }
    else if(op=="*"){
        readMultiplication(storeVar,operand1,operand2,lineNum);
    }
    else if(op=="/"){
        readDivision(storeVar,operand1,operand2,lineNum);
    }
    else if(op=="%"){
        readRemainder(storeVar,operand1,operand2,lineNum);
    }

}

void readAddition(string storeVar,string op1,string op2,int lineNum)
{
    cout << "In line " << lineNum+1 << " >> "
            << op1<<" and "<<op2<<" are added and assigned to "<<storeVar<<endl;
}
void readSubtraction(string storeVar,string op1,string op2,int lineNum)
{
    cout << "In line " << lineNum+1 << " >> "
            << op1<<" and "<<op2<<" are subtracted and assigned to "<<storeVar<<endl;
}
void readMultiplication(string storeVar,string op1,string op2,int lineNum)
{
    cout << "In line " << lineNum+1 << " >> "
            << op1<<" and "<<op2<<" are multipied and assigned to "<<storeVar<<endl;
}
void readDivision(string storeVar,string op1,string op2,int lineNum)
{
    cout << "In line " << lineNum+1 << " >> "
            << op1<<" is divided by "<<op2<<" and assigned to "<<storeVar<<endl;
}
void readRemainder(string storeVar,string op1,string op2,int lineNum)
{
    cout << "In line " << lineNum+1 << " >> "
            << op1<<" is divided by "<<op2<<" and Remainder is assigned to "<<storeVar<<endl;
}