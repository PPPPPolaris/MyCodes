//
// Created by MR on 2023/10/31.
//
#include "stdio.h"
int fac(int x)
{
    if(x==0||x==1)
        return 1;
    else
        return x* fac(x-1);
}
int main()
{

    int x;
    printf("x=");
    scanf("%d",&x);
    printf("x!=%d", fac(x));
}