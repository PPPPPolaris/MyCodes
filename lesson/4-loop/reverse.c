//
// Created by MR on 2023/10/21.
//
#include "stdio.h"
int main(void)
{
    int array[10];
    printf("Enter 10 numbers:");
    for (int i = 0; i < 10; ++i) {
        scanf("%d",&array[i]);
    }
    printf("In reverse order:");
    for (int i = 9; i >=0 ; --i) {
        printf("%d ",array[i]);
    }
    return 0;
}