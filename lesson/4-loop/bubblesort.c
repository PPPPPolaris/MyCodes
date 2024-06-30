//
// Created by MR on 2023/10/21.
//
#include "stdio.h"
int main(void)
{
    int array[9];
    printf("Enter 9 numbers:");
    for (int i = 0; i < 9; ++i) {
        scanf("%d", &array[i]);
    }
    printf("Numbers in order:");
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9-i-1; ++j) {
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    for (int i = 0; i < 9; ++i) {
        printf("%d ",array[i]);
    }
    return 0;
}
