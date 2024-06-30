//
// Created by Polaris on 2023/11/2.
//
#include "stdio.h"
int fib(int n)
{
    if(n==0||n==1)
        return n;
    else
        return fib(n-1)+ fib((n-2));
}
int main(void)
{
    int n;
    scanf("%d",&n);
    printf("fib(%d)=%d",n, fib(n));
    return 0;
}