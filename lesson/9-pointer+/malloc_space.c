//
// Created by MR on 2023/11/21.
//
#include "stdio.h"
#include "stdlib.h"
int main(void)
{
    void *p=NULL;
    int count=0;
    while ((p= malloc(100 * 1024 * 1024)))
    {
        count++;
    }
    printf("%d00MB\n",count);
    return 0;
}