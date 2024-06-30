//
// Created by MR on 2023/11/13.
//
#include "stdio.h"
int tiles(int n)
{
    if(n==2||n==1)
        return n;
    else
        return tiles(n-1)+ tiles(n-2);
}
int main(void)
{
    int n;
    scanf("%d",&n);
    printf("%d", tiles(n));
    return 0;
}