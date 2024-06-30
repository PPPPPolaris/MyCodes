//
// Created by MR on 2023/11/14.
//
#include "stdio.h"
void swap(int *pa,int *pb)
{
    int tmp=*pa;
    *pa=*pb;
    *pb=tmp;
}
int main(void)
{
    int a=5,b=6;
    swap(&a,&b);
    printf("a=%d,b=%d",a,b);
    return 0;
}