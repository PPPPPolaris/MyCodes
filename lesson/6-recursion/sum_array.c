//
// Created by MR on 2023/11/2.
//
#include "stdio.h"
#define MAX 4
int sum_array(int a[],int len)
{
    if(len==1)
        return a[0];
    else
        return sum_array(a,len-1)+ a[len-1];
}
int main(void)
{
    int a[MAX]={1,3,5,7};
    printf("%d", sum_array(a,MAX));
    return 0;
}