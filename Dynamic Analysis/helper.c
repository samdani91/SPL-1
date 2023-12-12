#include<stdio.h>

void helper(int x,int y,int z){
    FILE *fp;
    fp=fopen("output.txt","a");
    fprintf(fp,"%d %d %d\n",x,y,z);
}