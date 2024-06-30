//
// Created by MR on 2023/11/13.
//
#include "stdio.h"
int pascal(int up,int down)
{
    if(up==0||down==up)
        return 1;
    else
        return pascal(up-1,down-1)+ pascal(up,down-1);
}
int main(void)
{
    int row,loc;
    scanf("%d%d",&row,&loc);
    printf("%d", pascal(loc-1,row-1));
    return 0;
}