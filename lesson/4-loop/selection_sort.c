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
        int min = array[i];
        int count = i;
        for (int j = i + 1; j < 9; ++j) {
            if (array[j] < min) {
                min = array[j];
                count = j;
            }
        }
        if(i!=count)
        {
            int temp=array[i];
            array[i]=array[count];
            array[count]=temp;
        }
        printf("%d ",array[i]);
    }
    return 0;
}