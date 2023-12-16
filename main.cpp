#include <iostream>
#include "TokenHeader.h"
#include "interpret.h"


int main()
{
    string inputCode = readInputCode();
    int totalLines = inputCodeInLineByLine(inputCode);
    cout<<totalLines<<endl;
    tokenization(totalLines);
    cout<<"\t\t\t---------------Interpretation----------------"<<endl;
    cout<<endl;

    interpretation();

    return 0;
}
