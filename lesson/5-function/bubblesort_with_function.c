//
// Created by MR on 2023/10/24.
//
#include "stdio.h"
void bubble_sort(int array[],int len)
{
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len-i-1; ++j) {
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}
int main(void)
{
    int array[9];
    for (int i = 0; i < 9; ++i) {
        scanf("%d",&array[i]);
    }
    bubble_sort(array,9);
    for (int i = 0; i < 9; ++i) {
        printf("%d ",array[i]);
    }
    return 0;
}