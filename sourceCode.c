#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{   
    int p,q,r;
    float x=11;
    printf("%f",x);
    float y=15;
    int z;
    scanf("%d",&z);

    int n;
    scanf("%d",&n);

    int *ptr;
    float *ptr2;

    char str[10];
    char str2[10];

    strcpy(str2,str);
    strcat(str,str2);

    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=1;i<=3;i++){
        printf("%d",arr[i]);
    }
    int j=0;
    while(j<3){
        printf("%d",j);
        j++;
    }
    if(x!=10){
        printf("HelloWorld");
    }
    else{
        printf("TataWorld");
    }

    return 0;
}