//
// Created by Polaris on 2023/11/2.
//
#include "stdio.h"
#define MAX 10
int binary_search(const int array[],int left,int right,int key)
{
    if(left>right)
        return -1;
    else {
        int mid = (left + right) / 2;
        if (key == array[mid])
            return mid;
        else if (key > array[mid]) {
            binary_search(array, mid + 1, right, key);
        } else
            binary_search(array, left, mid - 1, key);
    }
}
int main(void)
{
    int array[MAX]={0,1,2,3,5,8,13,21,34,55};
    int key;
    scanf("%d",&key);
    if(binary_search(array,0,9,key)==-1)
        printf("Not Found!");
    else
        printf("Index:%d",binary_search(array,0,9,key));
    return 0;
}