//
// Created by MR on 2023/11/13.
//
#include "stdio.h"
#define MAX 100000
int leader[MAX]={0};
int find(int num)
{
    if(leader[num]==num)
        return num;
    else
        return find(leader[num]);
}
int main(void)
{
    int num;
    scanf("%d",&num);
    for (int i = 1; i <= num; ++i) {
        scanf("%d",&leader[i]);
    }
    for (int i = 1; i <=num ; ++i) {
        printf("%d ", find(i));
    }
    return 0;
}