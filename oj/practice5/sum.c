//
// Created by MR on 2023/10/27.
//
#include <math.h>
#include "stdio.h"
int sum;
int main(void)
{
    int n,t;
    scanf("%d %d",&n,&t);
    for (int i = 0; i < n; ++i) {
        int num=0;
        for (int j = 0; j <= i; ++j) {
            num+=t*pow(10,j);
        }
        sum+=num;
    }
    printf("%d",sum);
    return 0;
}