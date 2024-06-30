//
// Created by Polaris on 2023/11/14.
//
#include "stdio.h"
int *max(int a[],int len)
{
    int max=a[0];
    int loc_max=0;
    for (int i = 0; i < len; ++i) {
        if(a[i]>max) {
            max = a[i];
            loc_max = i;
        }
    }
    return &a[loc_max];
}
int main(void )
{
    int a[5]={1,2,3,4,5};
    printf("MAX:%d", *max(a,5));
    return 0;
}