//
// Created by MR on 2023/12/28.
//
#include "stdio.h"
#include "stdlib.h"
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main(void){
    int n;
    int arr[1005]={0};
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof (int),cmp);
    for (int i = 0; i < n; ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}