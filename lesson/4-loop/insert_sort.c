//
// Created by MR on 2023/10/21.
//
#include "stdio.h"
int main(void)
{
    int array[10000];
    int len;
    scanf("%d",&len);
    for (int i = 0; i < len; ++i) {
        scanf("%d",&array[i]);
    }
    /*for (int i = 1; i < len; ++i) {
        for (int j = i-1; j >=0 ; --j) {
            if(array[i]>array[j]){
                for (int k = i; k>=j+1 ; --k) {
                    int temp=array[k];
                    array[k]=array[k-1];
                    array[k-1]=temp;
                }
            }
        }
    }*/
    for (int i = 1; i <len ; ++i) {
        int insert=array[i];//determine which card to move
        int j;
        for (j = i-1; j >=0 ; --j) {//check cards in front of insert
             if(array[j]>insert)
                 array[j+1]=array[j];//put the larger one back
             else
                 break;
        }
        array[j+1]=insert;//put insert into the back of the first smaller one
    }
    for (int i = 0; i < len; ++i) {
        printf("%d ",array[i]);
    }
    return 0;
}