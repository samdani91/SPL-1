#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    float x=11;
    printf("%f",x);
    float y=15;
    int z;
    scanf("%d",&z);

    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=1;i<=3;i++){
        printf("%d",i);
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