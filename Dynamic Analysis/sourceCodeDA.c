#include<stdio.h>

int main()
{   
    int x,y,z;
    x=10;
    y=20;
    z=x+y;
    for(int i=1;i<=10;i++){
        x+=i;
    }
    x=x+40;
    y=y+10;
    z=x+y;
    if(!x){
        x=0;
    }
    else if(!y){
        y=0;
    }
    else if(!z){
        z=0;
    }
    else{
        x=0;
        y=0;
        z=0;
    }
    return 0;
}