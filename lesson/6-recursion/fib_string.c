//
// Created by MR on 2023/11/2.
//
#include "stdio.h"
void fib_string(int n)
{
    if(n==0)
        printf("b");
    else if(n==1)
        printf("a");
    else {
        fib_string(n - 1);
        fib_string(n-2);
    }
}
int main(void)
{
    int n;
    scanf("%d",&n);
    //fib_string(n);
    for (int i = 0; i <= n; ++i) {
        fib_string(i);
        printf("\n");
    }
    return 0;
}