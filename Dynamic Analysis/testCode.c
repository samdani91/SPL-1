#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "helper.c"

int main()
{
    int x,y,z;
    x=10;
    y=20;
    z=x+y;

    x=x+40;
    y=y+10;
    z=x+y;
    
    helper(x,y,z);
    return 0;
}
