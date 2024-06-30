//
// Created by MR on 2023/10/10.
//
#include "stdio.h"
int main(void)
{
    int n,count=0;
    scanf("%d",&n);
    int max;
    int a[10000];
    while (n !=1)
    {
        a[count]=n;
        if(n%2==0){
            n = n / 2;
        }
        else{
            n = 3 * n+1;
        }
        count=count+1;
    }
    for (int i = 0; i < count; ++i) {
        if(a[i]>a[i+1]){
            int tmp=a[i];
            a[i]=a[i+1];
            a[i+1]=tmp;
        }
    }
    max=a[count];
    printf("%d %d",count,max);

    return 0;
}