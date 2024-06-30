//
// Created by MR on 2023/11/3.
//
#include <assert.h>
#include "stdio.h"
#define MAX 10
int quick_sort_swap(int array[],int pivot,int left,int right)
{
    int tmp[MAX]={0};
    for (int i = left; i <= right ; ++i) {
        tmp[i] = array[i];
    }
    int low=left,high=right;
    for (int i = left; i <=right ; ++i) {
        if(i==pivot)
            continue;
        if(tmp[i]<=tmp[pivot]) {
            array[low] = tmp[i];
            low++;
        } else if(tmp[i]>tmp[pivot]){
            array[high]=tmp[i];
            high--;
        }
    }
    assert(low==high);
    array[low]=tmp[pivot];
    return low;
}
void quick_sort(int array[],int left,int right)
{
    if(left>=right)
        return;
    int pivot=(left+right)/2;
    pivot= quick_sort_swap(array,pivot,left,right);
    quick_sort(array,left,pivot-1);
    quick_sort(array,pivot+1,right);
}
int main(void)
{
    int nums[MAX]={3,7,8,5,2,1,9,5,4,0};
    quick_sort(nums,0,9);
    for (int i = 0; i < MAX; ++i) {
        printf("%d ",nums[i]);

    }
    return 0;
}