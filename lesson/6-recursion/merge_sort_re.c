//
// Created by Polaris on 2023/11/2.
//
#include "stdio.h"
#define MAX 10
void printArr(int array[],int left,int right){
    for (int i = left; i <= right; ++i) {
        printf("%d ",array[i]);
    }
}
void merge(int array[],int left,int mid,int right);
void merge_sort(int array[],int left,int right)
{
    if(left==right)
        return;
    else
    {
        int mid=(left+right)/2;
        merge_sort(array,left,mid);
        merge_sort(array,mid+1,right);
        merge(array,left,mid,right);
    }
}
int main(void)
{
    int array[MAX]={6,2,4,1,5,7,3,8,9,0};
    merge_sort(array,0,9);
    for (int i = 0; i < MAX; ++i) {
        printf("%d ",array[i]);
    }
    return 0;
}
void merge(int array[],int left,int mid,int right)
{
    int tmpA[MAX],tmpB[MAX];
    for (int i = left; i <=mid ; ++i) {
        tmpA[i]=array[i];
    }
    for (int i = mid+1; i <=right ; ++i) {
        tmpB[i]=array[i];
    }
    int a=left,b=mid+1,i=left;
    while (a<=mid && b<=right){
        if(tmpA[a]<=tmpB[b]){
            array[i]=tmpA[a];
            a++;
        } else{
            array[i]=tmpB[b];
            b++;
        }
        i++;
    }
    if(a<=mid){
        for (int j = a; j <=mid ; ++j) {
            array[i]=tmpA[j];
            i++;
        }
    }
    if(b<=right){
        for (int j = b; j <=right ; ++j) {
            array[i]=tmpB[j];
            i++;
        }
    }
}